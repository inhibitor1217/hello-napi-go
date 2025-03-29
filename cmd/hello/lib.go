package hello

import "C"

import "fmt"

//export hello
func hello() {
	fmt.Println("Hello, World!")
}

//export add
func add(a, b C.int) C.int {
	return a + b
}

func main() {}
