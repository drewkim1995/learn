package main

import (
	"log"
	"net/http"

	"news-article/database"

	"github.com/gorilla/mux"
	// _ "github.com/lib/pq"
)

func handleRequests() {
	// creates a new instance of a mux router
	myRouter := mux.NewRouter().StrictSlash(true)

	// Could also specify routes of a certain subdomain
	// myRouter.Host("{subdomain:[a-z]+}.example.com")
	myRouter.HandleFunc("/articles", receiveArticle).Host("localhost:10000").Methods("POST")
	myRouter.HandleFunc("/articles/{id}", retrieveArticle).Host("localhost:10000").Methods("GET")
	myRouter.HandleFunc("/tags/{tagName}/{date}", retrieveTags).Host("localhost:10000").Methods("GET")
	log.Fatal(http.ListenAndServe(":10000", myRouter))
}

func main() {
	database.Connect()
	handleRequests()
}

/* List of resources used:
https://tutorialedge.net/golang/creating-restful-api-with-golang/
https://stackoverflow.com/a/8271160
https://www.golangprograms.com/go-language/struct.html
https://stackoverflow.com/questions/4278430/convert-string-to-integer-type-in-go
https://blog.golang.org/slices
https://stackoverflow.com/questions/53737435/how-to-prepend-int-to-slice
https://www.calhoun.io/connecting-to-a-postgresql-database-with-gos-database-sql-package/
https://www3.ntu.edu.sg/home/ehchua/programming/sql/Relational_Database_Design.html
http://go-database-sql.org/accessing.html
https://stackoverflow.com/questions/38607733/sorting-a-uint64-slice-in-go
https://blog.logrocket.com/the-essential-guide-for-designing-a-production-ready-developer-friendly-restful-api/

https://stackoverflow.com/questions/21743841/how-to-avoid-annoying-error-declared-and-not-used
https://github.com/gorilla/mux
https://blog.golang.org/using-go-modules
https://developer.mozilla.org/en-US/docs/Web/HTTP/Status

Tested using:
http://localhost:10000/tags/health/19560915
http://localhost:10000/tags/health/20160922
http://localhost:10000/tags/health/20160923
*/
