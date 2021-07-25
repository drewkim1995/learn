package database

import (
	"database/sql"
	"fmt"
	// _ "github.com/lib/pq"
)

const (
	host     = "localhost"
	port     = 5432
	user     = "postgres"
	password = "secret-pwd"
	dbname   = "fairfax-media"
)

/*
Structures that start with uppercase are exported to other packages,
Names starting with lowercase are only local, the fields must be upper
so that the JSON package can see them.

Assuming that Id will always be an unsigned integer, and that the Id
is from a database where it is like: NOT NULL AUTO_INCREMENT.
*/
type Article struct {
	Id    uint64   `json:"id"`
	Title string   `json:"title"`
	Date  string   `json:"date"`
	Body  string   `json:"body"`
	Tags  []string `json:"tags"`
}

// mock DB table
type db_articles struct {
	id    uint64
	title string
	date  string
	body  string
}

// mock DB table
type db_tags struct {
	id   uint64
	name string
}

// mock DB table
type db_article_tags struct {
	id         uint64
	article_id uint64
	tag_id     uint64
}

// Global
var db sql.DB
var table_articles []db_articles
var table_tags []db_tags
var table_article_tags []db_article_tags

func Connect() {
	psqlInfo := fmt.Sprintf("host=%s port=%d user=%s "+
		"password=%s dbname=%s sslmode=enable",
		host, port, user, password, dbname)

	// sql.Open only validates args provided
	db, err := sql.Open("postgres", psqlInfo)
	if err != nil {
		// Note: Didn't setup a server due to time-constraints
		// panic(err)

		// No demo Database, faking some data
		InsertArticle("latest science shows that potato chips are better for you than sugar", "2016-09-22", "some text, potentially containing simple markup about how potato chips are great", []string{"health", "fitness", "science"})
		InsertArticle("latest science shows that sugar is better for you than potato chips", "2016-09-22", "some text, potentially containing simple markup about how potato chips are great", []string{"health", "potato", "science"})
		InsertArticle("Article 3", "2016-09-22", "...words.", []string{"coding"})
		InsertArticle("Article 4", "2016-09-22", "...words.", []string{"development"})
		InsertArticle("Article 5", "2016-09-22", "...words.", []string{"example"})
		InsertArticle("Article 6", "2016-09-22", "...words.", []string{"understand"})
		InsertArticle("Article 7", "2016-09-22", "...words.", []string{"parameter"})
		InsertArticle("Article 8", "2016-09-22", "...words.", []string{"HYPHEN"})
		InsertArticle("Article 9", "2016-09-22", "...words.", []string{"structured"})
		InsertArticle("Article 10", "2016-09-22", "...words.", []string{"submissions"})
		InsertArticle("Article 11", "2016-09-22", "...words.", []string{"given"})
		InsertArticle("Article 12", "2016-09-22", "...words.", []string{"language"})
		InsertArticle("Article 13", "2016-09-22", "...words.", []string{"health", "different"})
		InsertArticle("Article 14", "2016-09-23", "...words.", []string{"science"})
		InsertArticle("Article 15", "2016-09-23", "...words.", []string{"health", "random"})
		return
	}
	defer db.Close()

	// Actually open connection to DB
	err = db.Ping()
	if err != nil {
		panic(err)
	}
}
