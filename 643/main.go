package main

import (
	"fmt"
	"math"
)

func findMaxAverage(nums []int, k int) float64 {
	sum := 0
	maxSum := math.MinInt64

	for i := 0; i < len(nums); i++ {
		sum += nums[i]
		if i >= k {
			sum -= nums[i-k]
		}
		if i >= k-1 && sum > maxSum {
			maxSum = sum
		}
	}

	return float64(maxSum) / float64(k)
}

func main() {
	nums := []int{1, 12, -5, -6, 50, 3}
	k := 4
	fmt.Println(findMaxAverage(nums, k))
}
