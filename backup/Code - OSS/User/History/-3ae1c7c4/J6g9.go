package main

import(
	"fmt"
	"net/http"
)

type Aircraft struct{
	Name      string `json:"name"`
	Country   string `json:"country"`
	Role      string `json:"role"`
	SpeedKMH  int    `json:"speed_kmh"`
	Crew      int    `json:"crew"`
}

func

func main(){
//	http.HandleFunc("/",home)
	fmt.Println("Server running on port 6969")
	http.ListenAndServe(":6969",nil)
}