package main

import (
	"encoding/json"
	"io/ioutil"
	"net/http"
	"news-article/database"
)

type rxArticle struct {
	Title string
	Date  string
	Body  string
	Tags  []string
}

// 1st Endpoint
func receiveArticle(w http.ResponseWriter, r *http.Request) {
	reqBody, _ := ioutil.ReadAll(r.Body)
	var article rxArticle

	// Doing a very basic unencrypted auth system for the purposes of showing different error responses
	// Realistically we would use API key
	usr, pwd, ok := r.BasicAuth()
	if !ok {
		http.Error(w, http.StatusText(http.StatusUnauthorized), http.StatusUnauthorized)
		return
	}

	if usr == "editorialMember" && pwd == "editorialPassword" {
		// Keys preferring an exact match but also accepting a case-insensitive match.
		// By default, object keys which don't have a corresponding struct field are ignored.
		err := json.Unmarshal(reqBody, &article)
		if err == nil && article.Title != "" && article.Date != "" && article.Body != "" && len(article.Tags) > 0 {
			// We should also do a check here to make sure that the article doesn't already exist in the database.

			// if database.InsertArticleDb(article.Title, article.Date, article.Body, article.Tags)
			if database.InsertArticle(article.Title, article.Date, article.Body, article.Tags) {
				http.Error(w, "Successfully processed article.", http.StatusOK)
				return
			}
		}

		http.Error(w, "Error processing article.", http.StatusBadRequest)
		return
	}

	http.Error(w, http.StatusText(http.StatusForbidden), http.StatusForbidden)
}
