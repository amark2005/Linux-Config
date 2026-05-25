package main

import(
	"fmt"
	"net/http"
)

type Aircraft struct{
	Name        string `json:"name"`
	Country     string `json:"country"`
	Speed       string `json:"speed"`
	Role        string `json:"role"`
	FirstFlight int    `json:"first_flight"`
}

var airy=[]Aircraft{
	
}

func

func main(){
//	http.HandleFunc("/",home)
	fmt.Println("Server running on port 6969")
	http.ListenAndServe(":6969",nil)
}