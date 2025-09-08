package main

import (
	"fmt"
	"strconv"
	"strings"
)

func check(n int) bool {
	return strings.Contains(strconv.Itoa(n), "0")
}

func getNoZeroIntegers(n int) []int {
	for i := 1; i < n; i++ {
		if !check(i) && !check(n-i) {
			return []int{i, n - i}
		}
	}

	return nil
}

func main() {
	fmt.Println(getNoZeroIntegers(11))
}
