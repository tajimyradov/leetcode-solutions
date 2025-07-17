package main

import "fmt"

func maximumLength(nums []int, k int) int {
	maxLen := 1

	for t := 0; t < k; t++ {
		dp := make(map[int]int)
		curMax := 0

		for _, num := range nums {
			m := num % k
			want := (t - m + k) % k

			length := dp[want] + 1
			if length > dp[m] {
				dp[m] = length
			}

			if dp[m] > curMax {
				curMax = dp[m]
			}
		}

		if curMax > maxLen {
			maxLen = curMax
		}
	}

	return maxLen
}

func main() {
	nums := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52}
	res := maximumLength(nums, 2)

	fmt.Println(res)
}
