package main

import(
	"fmt"
	"net/http"
	"encoding/json"
	"math/rand"
	"time"
)

type Aircraft struct{
	Name        string `json:"name"`
	Country     string `json:"country"`
	Speed       string `json:"speed"`
	Role        string `json:"role"`
	FirstFlight int    `json:"first_flight"`
}

var airy=[]Aircraft{
	{
		Name:        "B-2 Spirit",
		Country:     "USA",
		Speed:       "Mach 0.95",
		Role:        "Stealth Bomber",
		FirstFlight: 1989,
	},
	{
		Name:        "F-22 Raptor",
		Country:     "USA",
		Speed:       "Mach 2.25",
		Role:        "Air Superiority Fighter",
		FirstFlight: 1997,
	},
	{
		Name:        "Su-57",
		Country:     "Russia",
		Speed:       "Mach 2",
		Role:        "Multirole Stealth Fighter",
		FirstFlight: 2010,
	},
	{
		Name:        "Dassault Rafale",
		Country:     "France",
		Speed:       "Mach 1.8",
		Role:        "Multirole Fighter",
		FirstFlight: 1986,
	},
	{
		Name:        "J-20",
		Country:     "China",
		Speed:       "Mach 2",
		Role:        "Stealth Fighter",
		FirstFlight: 2011,
	},
}

func airyhandler(w http.ResponseWriter,r *http.Request){

}

func main(){
//	http.HandleFunc("/",home)
	fmt.Println("Server running on port 6969")
	http.ListenAndServe(":6969",nil)
}