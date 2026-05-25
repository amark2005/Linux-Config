package main

import(
	"fmt"
	"net/http"
)

type Aircraft struct{
	Name string `json:"name"`
}

func main(){
//	http.HandleFunc("/",home)
	fmt.Println("Server running on port 6969")
	http.ListenAndServe(":6969",nil)
}