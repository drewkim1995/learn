package main

import (
	"encoding/json"
	"net/http"
	"news-article/database"
	"strconv"

	"github.com/gorilla/mux"
)

// 2nd Endpoint
func retrieveArticle(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	keyString := vars["id"]

	// Error Handle if Id is not an Uint64
	key, err := strconv.ParseUint(keyString, 10, 64)
	if err != nil {
		http.Error(w, "Error: Check the article ID.", http.StatusBadRequest)
		return
	}

	var article database.Article
	err = database.GetArticle(key, &article)
	if err != nil {
		http.Error(w, err.Error(), http.StatusNotFound)
		return
	}
	w.Header().Add("Content-Type", "application/json")
	json.NewEncoder(w).Encode(article)
}
