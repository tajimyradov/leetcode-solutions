package main

import "fmt"

func tribonacci(n int) int {
	t3 := 0
	t2 := 1
	t1 := 1
	if n == 0 {
		return t3
	}
	if n == 1 {
		return t2
	}
	if n == 2 {
		return t1
	}
	var t int
	for i := 3; i <= n; i++ {
		t = t1 + t2 + t3
		t3 = t2
		t2 = t1
		t1 = t
	}
	return t
}

func main() {
	fmt.Println(tribonacci(4))
	fmt.Println(tribonacci(25))
}
