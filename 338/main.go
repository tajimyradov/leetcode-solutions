package main

import (
	"fmt"
)

func countBits(n int) []int {
	dp := make([]int, n+1)
	dp[0] = 0
	for i := 1; i <= n; i++ {
		dp[i] = dp[i>>1] + (i & 1)
	}
	return dp
}

func main() {
	fmt.Println(countBits(5))
}
