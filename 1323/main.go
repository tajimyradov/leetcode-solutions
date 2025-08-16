package main

import (
	"fmt"
	"strconv"
)

func maximum69Number(num int) int {
	s := strconv.Itoa(num)

	for i := 0; i < len(s); i++ {
		if string(s[i]) == "6" {
			s = s[:i] + "9" + s[i+1:]
			break
		}
	}

	res, _ := strconv.Atoi(s)
	return res
}

func main() {
	fmt.Println(maximum69Number(9669))
}
