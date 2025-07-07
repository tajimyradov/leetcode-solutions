package main

import (
	"fmt"
)

func longestSubsequence(s string, k int) int {
	n := len(s)
	zeroCount := 0
	oneCount := 0
	currentValue := int64(0)
	bitValue := int64(1)
	k64 := int64(k)

	for _, c := range s {
		if c == '0' {
			zeroCount++
		}
	}

	for i := n - 1; i >= 0; i-- {
		if s[i] == '1' {
			if currentValue+bitValue <= k64 {
				currentValue += bitValue
				oneCount++
			}
		}
		bitValue <<= 1
		if bitValue > k64 {
			break
		}
	}

	return zeroCount + oneCount
}

func main() {
	fmt.Print(longestSubsequence("001010101011010100010101101010010", 93951055))
}
