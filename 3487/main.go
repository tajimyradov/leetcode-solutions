package main

import "fmt"

func maxSum(nums []int) int {
	mx := nums[0]
	res := make(map[int]bool)
	sum := 0

	for i := 0; i < len(nums); i++ {
		if nums[i] > mx {
			mx = nums[i]
		}
		if nums[i] > 0 && res[nums[i]] == false {
			res[nums[i]] = true
			sum += nums[i]
		}
	}
	if mx < 0 {
		return mx
	}

	return sum
}

func main() {
	nums := []int{1, 2, 3, 4, 5}
	fmt.Println(maxSum(nums))
}
