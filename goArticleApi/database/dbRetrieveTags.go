package database

import (
	"fmt"
	"sort"
	// _ "github.com/lib/pq"
)

type TagInfo struct {
	Tag          string   `json:"tag"`
	Count        uint64   `json:"count"`
	Articles     []uint64 `json:"articles"`
	Related_tags []string `json:"related_tags"`
}

func GetTagInfo(date string, result *TagInfo) error {
	var tagId uint64
	tagFound := false
	for _, tag := range table_tags {
		if tag.name == result.Tag {
			tagFound = true
			tagId = tag.id
			break
		}
	}

	if !tagFound {
		return fmt.Errorf("Error: Tag Not Found.")
	}

	// Real-world scenario there is a caching server to minimise database access
	// So we would probably check the hash and return previously cached value if
	// the database hasn't changed and updated.

	var articlesFromDate []uint64
	for _, article := range table_articles {
		if article.date == date {
			articlesFromDate = append(articlesFromDate, article.id)
		}
	}

	// Get the Number of Tags for the tagName that day
	result.Count = 0
	var articlesFromDateWithTag []uint64
	for _, articleTag := range table_article_tags {
		for _, articleId := range articlesFromDate {
			if articleTag.article_id == articleId && articleTag.tag_id == tagId {
				result.Count++
				articlesFromDateWithTag = append(articlesFromDateWithTag, articleTag.article_id)
			}
		}
	}

	// Get Related Tags
	var relatedTags []uint64
	for _, articleTag := range table_article_tags {
		for _, articleId := range articlesFromDateWithTag {
			if articleTag.article_id == articleId {
				relatedTags = append(relatedTags, articleTag.tag_id)
			}
		}
	}

	// Sort before they're strings for performance (weird to say after all the O(n^2) time complexity)
	sort.Slice(relatedTags, func(i, j int) bool { return relatedTags[i] < relatedTags[j] })

	// Remove Duplicates
	var tags []uint64
	if len(relatedTags) > 0 {
		tags = append(tags, relatedTags[0])

		for _, tag := range relatedTags {
			if tags[len(tags)-1] != tag {
				tags = append(tags, tag)
			}
		}
	}

	for _, i := range tags {
		result.Related_tags = append(result.Related_tags, table_tags[i].name)
	}

	// Assuming date entered is same as ID's, incrementing and not going back.
	// This is done in reverse as the description of this task specifies
	// "last 10 articles entered for that day."
	for i := len(table_articles) - 1; i >= 0; i-- {
		if table_articles[i].date == date {
			result.Articles = append([]uint64{table_articles[i].id}, result.Articles...) // Prepend
		}

		// Note: We could also break loop earlier by checking if the
		// Articles[i].Date is older than the date
		if len(result.Articles) > 10 {
			break
		}
	}

	// Return type Error incase a database call fails
	return nil
}

func GetTagInfoDb(result *TagInfo) error {
	// Time-constraint
	return nil
}
