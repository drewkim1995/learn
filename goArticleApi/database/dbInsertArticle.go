package database

import (
	"database/sql"
	"strings"
	// _ "github.com/lib/pq"
)

func InsertArticle(title string, date string, body string, tags []string) bool {
	// Insert into articles
	articleId := uint64(len(table_articles))
	table_articles = append(table_articles, db_articles{id: articleId, title: title, date: date, body: body})

	// Find or Insert into tags
	var tagIds []uint64
	for _, tag := range tags {
		var tagId uint64 = uint64(len(table_tags))
		found := false

		// Convert to lowercase for tags to avoid duplicates
		tag = strings.ToLower(tag)

		// Terrible performance on write, better on read
		for _, table_tag := range table_tags {
			if table_tag.name == tag {
				tagId = table_tag.id
				found = true
				break
			}
		}

		if !found {
			table_tags = append(table_tags, db_tags{id: tagId, name: tag})
		}

		// Store all tagIds
		tagIds = append(tagIds, tagId)
	}

	// Insert into article_tags
	for _, tagId := range tagIds {
		articleTagId := uint64(len(table_article_tags))
		table_article_tags = append(table_article_tags, db_article_tags{id: articleTagId, article_id: articleId, tag_id: tagId})
	}

	return true
}

func InsertArticleDb(title string, date string, body string, tags []string) bool {
	// Insert into articles
	insertArticleSql := `
		INSERT INTO articles (title, date, body)
		VALUES ($1, $2, $3)
		RETURNING id`
	articleId := 0
	err := db.QueryRow(insertArticleSql, title, date, body).Scan(&articleId)
	if err != nil {
		// panic(err)
	}

	// Find or Insert into tags
	selectTagSql := `
		select id
		FROM tags
		WHERE id == $1`
	insertTagSql := `
		INSERT INTO tags (name)
		VALUES ($1)
		RETURNING id`
	var tagIds []uint64

	// Time-constraint: There is a more efficient way to do find else insert
	for _, tag := range tags {
		var tagId uint64 = 0

		// Convert to lowercase for tags to avoid duplicates
		tag = strings.ToLower(tag)

		// Get the ID if tag exists
		err := db.QueryRow(selectTagSql, tag).Scan(&tagId)
		if err == sql.ErrNoRows {
			// Else insert into database
			err := db.QueryRow(insertTagSql, tag).Scan(&tagId)
			if err != nil {
				// panic(err)
			}
		} else if err != nil {
			// panic(err)
		}

		// Store all tagIds
		tagIds = append(tagIds, tagId)
	}

	// Insert into article_tags
	insertArticleTagSql := `
		INSERT INTO article_tags (article_id, tag_id)
		VALUES ($1, %2)`
	for _, tagId := range tagIds {
		_, err = db.Exec(insertArticleTagSql, articleId, tagId)
		if err != nil {
			// panic(err)
		}
	}

	// Note: To improve this we should validate the data and make sure all transactions happen.

	return true
}
