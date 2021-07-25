package main

import (
	"encoding/json"
	"net/http"
	"news-article/database"

	"github.com/gorilla/mux"
)

// 3rd Endpoint
func retrieveTags(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	tagName := vars["tagName"]
	date := vars["date"]

	// Validate data
	if tagName == "" {
		http.Error(w, "Error: Tag Not Found.", http.StatusBadRequest)
		return
	}
	if date == "" || len(date) != 8 {
		http.Error(w, "Error: Invalid Date.", http.StatusBadRequest)
		return
	}

	// For testing later, convert path variable to match database variable
	date = date[:4] + "-" + date[4:6] + "-" + date[6:8]

	var tagInfo database.TagInfo
	tagInfo.Tag = tagName
	err := database.GetTagInfo(date, &tagInfo)
	if err != nil {
		http.Error(w, err.Error(), http.StatusNotFound)
		return
	}

	w.Header().Add("Content-Type", "application/json")
	json.NewEncoder(w).Encode(tagInfo)
}
