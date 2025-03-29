package main

import "C"

import (
	"fmt"
	"sync"
	"sync/atomic"
)

//export hello
func hello() {
	fmt.Println("Hello, World!")
}

//export add
func add(a, b C.int) C.int {
	return a + b
}

//export fast_sum
func fast_sum(n C.int) C.int {
	wg := sync.WaitGroup{}
	wg.Add(int(n))
	sum := atomic.Int32{}
	for i := 0; i < int(n); i++ {
		go func() {
			defer wg.Done()
			sum.Add(1)
		}()
	}
	wg.Wait()
	return C.int(sum.Load())
}

func main() {}
