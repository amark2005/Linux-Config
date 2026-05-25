package main

import(
	"fmt"
	"net/http"
)



func main(){
//	http.HandleFunc("/",home)
	fmt.Println("Server running on port 6969")
	http.ListenAndServe(":6969",nil)
}