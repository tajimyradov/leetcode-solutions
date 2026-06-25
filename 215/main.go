package main

import (
	"fmt"
	"slices"
)

func findKthLargest(nums []int, k int) int {
	slices.Sort(nums)
	return nums[len(nums)-k]
}

func main() {
	nums := []int{3, 2, 1, 5, 6, 4}
	k := 2
	result := findKthLargest(nums, k)
	fmt.Println(result) // Output: 5
}
