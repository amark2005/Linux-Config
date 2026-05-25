package main

import "fmt"

func main() {
	fmt.Println("Enter Your Name: ")
	name:=""
	fmt.Scanln(name)
	fmt.Println("Enter Your age: ")
	age:=0
	fmt.Scanln(age)
	fmt.Println("Hello",name,", You are",age)
}
