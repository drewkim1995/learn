package database

import (
	"fmt"
	// _ "github.com/lib/pq"
)

func GetArticle(id uint64, article *Article) error {
	// Note: might need to handle if the key is > limit of int
	if int(id) >= len(table_articles) {
		return fmt.Errorf("Error: Article Not Found.")
	}

	// Real-world scenario there is a caching server to minimise database access
	// So we would probably check the hash and return previously cached value if
	// the database hasn't changed and updated.

	// In mock DB, the ID matches with array index
	article.Id = table_articles[id].id
	article.Title = table_articles[id].title
	article.Body = table_articles[id].body
	article.Date = table_articles[id].date

	// Get the Tags
	for _, articleTag := range table_article_tags {
		if articleTag.article_id == article.Id {
			article.Tags = append(article.Tags, table_tags[articleTag.tag_id].name)
		}
	}

	return nil
}

func GetArticleDb(id uint64, article *Article) error {
	// Time-constraint
	return nil
}
