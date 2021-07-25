package main

import (
	"bytes"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
)

const (
	LINE_FEED byte = 0x0A
)

type Article struct {
	Title string
	Date  string
	Body  string
	Tags  []string
	code  int
}

var articles = []Article{
	{
		Title: "Amazing title",
		Date:  "2021-06-16",
		Body:  "The body of the amazing article.",
		Tags: []string{
			"amazing", "structured", "random",
		},
		code: 200,
	},
	{
		Title: "Failed title",
		Date:  "2021-06-17",
		Body:  "Hope this fails",
		code:  400,
	},
}

var sendCount = 1
var successCount = 1

func sendPost(article Article, addr string, user string, expectedResult int) {
	payloadBuf := new(bytes.Buffer)
	json.NewEncoder(payloadBuf).Encode(article)
	req, _ := http.NewRequest("POST", addr, payloadBuf)
	req.Header.Add("Content-Type", "application/json")
	// Content-Length is already set by http.NewRequest
	// User-Agent is also set as "Go-http-client/1.1"

	// Simulate different levels of authentication
	if user == "editorial" {
		req.SetBasicAuth("editorialMember", "editorialPassword")
		fmt.Println("\r\nPOST Editorial Send: Article #", sendCount)
	} else if user == "registered" {
		req.SetBasicAuth("registeredMember", "registeredPassword")
		fmt.Println("\r\nPOST Registered Send: Article #", sendCount)
	} else {
		fmt.Println("\r\nPOST Unauth Send: Article #", sendCount)
	}

	client := &http.Client{}
	res, err := client.Do(req)
	if err != nil {
		fmt.Println("Failed POST on sending the", sendCount, "article.")
		log.Fatalln(err)
	}
	defer res.Body.Close()

	//Read the response
	body, err := ioutil.ReadAll(res.Body)
	if err != nil {
		fmt.Println("Failed POST on reading the response from the", sendCount, "article.")
		log.Fatalln(err)
	}
	sb := string(body)

	if res.StatusCode == expectedResult {
		successCount++
	} else {
		fmt.Println("Error, status code doesn't match.")
	}

	fmt.Println("Resp:", res.Status, "| Body:", sb)

	sendCount++
}

func sendGet(addr string, user string, expectedResult int, expectedBody string) {
	req, err := http.NewRequest("GET", addr, nil)
	if err != nil {
		log.Print(err)
		os.Exit(1)
	}

	// Simulate different levels of authentication
	if user == "editorial" {
		req.SetBasicAuth("editorialMember", "editorialPassword")
		fmt.Println("\r\nGET Editorial Send: Article #", sendCount)
	} else if user == "registered" {
		req.SetBasicAuth("registeredMember", "registeredPassword")
		fmt.Println("\r\nGET Registered Send: Article #", sendCount)
	} else {
		fmt.Println("\r\nGET Unauth Send: Article #", sendCount)
	}

	client := &http.Client{}
	res, err := client.Do(req)
	if err != nil {
		fmt.Println("Failed GET on sending the", sendCount, "article.")
		log.Fatalln(err)
	}
	defer res.Body.Close()

	// Read the response
	body, err := ioutil.ReadAll(res.Body)
	if err != nil {
		fmt.Println("Failed GET on reading the response from the", sendCount, "article.")
		log.Fatalln(err)
	}
	sb := string(body)

	// Seperated to keep code more readable
	if res.StatusCode == expectedResult {
		if expectedResult != 200 || (expectedResult == 200 && sb == expectedBody) {
			successCount++
		} else {
			fmt.Println("Error, body content doesn't match.")
		}
	} else {
		fmt.Println("Error, status code doesn't match.")
	}

	fmt.Println("Resp:", res.Status, "| Body:", sb)

	sendCount++
}

func main() {
	// Send 2 valid articles as non-user
	sendPost(articles[0], "http://localhost:10000/articles", "", 401)
	sendPost(articles[0], "http://localhost:10000/articles", "basic", 401)

	// Send 1 valid article as a registered user
	sendPost(articles[0], "http://localhost:10000/articles", "registered", 403)

	// Test getting valid articles
	sendGet("http://localhost:10000/articles/12", "", 200, "{\"id\":12,\"title\":\"Article 13\",\"date\":\"2016-09-22\",\"body\":\"...words.\",\"tags\":[\"health\",\"different\"]}"+string(LINE_FEED))
	sendGet("http://localhost:10000/articles/13", "registeredMember", 200, "{\"id\":13,\"title\":\"Article 14\",\"date\":\"2016-09-23\",\"body\":\"...words.\",\"tags\":[\"science\"]}"+string(LINE_FEED))
	sendGet("http://localhost:10000/articles/14", "editorialMember", 200, "{\"id\":14,\"title\":\"Article 15\",\"date\":\"2016-09-23\",\"body\":\"...words.\",\"tags\":[\"health\",\"random\"]}"+string(LINE_FEED))

	// Test getting an article with invalid ID
	// Note this one will fail if you run the test multiple times after the server is online due to hard-coded article ID.
	sendGet("http://localhost:10000/articles/12/weeeee", "", 404, "")
	sendGet("http://localhost:10000/articles/15", "editorialMember", 404, "{\"id\":15,\"title\":\"Amazing title\",\"date\":\"2021-06-16\",\"body\":\"The body of the amazing article.\",\"tags\":[\"amazing\",\"structured\",\"random\"]}"+string(LINE_FEED))

	// Test getting valid tag
	sendGet("http://localhost:10000/tags/health/20160923", "", 200, "{\"tag\":\"health\",\"count\":1,\"articles\":[13,14],\"related_tags\":[\"health\",\"random\"]}"+string(LINE_FEED))

	// Test getting tag not existing
	// Note this one will fail if you run the test multiple times after the server is online due to hard-coded tag.
	sendGet("http://localhost:10000/tags/amazing/20210616", "", 404, "")

	// Send 2 articles as editorial
	for _, article := range articles {
		sendPost(article, "http://localhost:10000/articles", "editorial", article.code)
	}

	// Test getting previous invalid ID article (we inserted it from above)
	sendGet("http://localhost:10000/articles/15", "editorialMember", 200, "{\"id\":15,\"title\":\"Amazing title\",\"date\":\"2021-06-16\",\"body\":\"The body of the amazing article.\",\"tags\":[\"amazing\",\"structured\",\"random\"]}"+string(LINE_FEED))

	// Test getting previous invalid tag (we inserted it from above)
	// Note this one will fail if you run the test multiple times after the server is online due to inserting article with same tag multiple times.
	// Realistically we probably would have something to check if the same article is attempted to being posted.
	sendGet("http://localhost:10000/tags/amazing/20210616", "", 200, "{\"tag\":\"amazing\",\"count\":1,\"articles\":[15],\"related_tags\":[\"structured\",\"random\",\"amazing\"]}"+string(LINE_FEED))

	// Test invalid URL
	sendPost(articles[0], "http://localhost:10000", "registered", 404)

	// Test sending POST to a GET API
	sendPost(articles[0], "http://localhost:10000/articles/14", "registered", 405)
	sendPost(articles[0], "http://localhost:10000/tags/health/20160923", "registered", 405)

	// Print Results
	if sendCount == successCount {
		fmt.Println("\r\nSuccessfully passed all", sendCount, "test cases.\r\n")
	} else {
		fmt.Println("\r\n\r\nError: Passed", successCount, "/", sendCount, "test cases.\r\n")
	}
}
