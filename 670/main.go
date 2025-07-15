package main

import (
	"fmt"
	"slices"
	"sort"
)

func maximumSwap(num int) int {
	var arr []int

	temp := num

	for num > 0 {
		arr = append(arr, num%10)
		num /= 10
	}

	if len(arr) == 1 {
		return arr[0]
	}

	slices.Reverse(arr)

	nums := make([]int, len(arr))

	copy(nums, arr)

	sort.Ints(nums)
	slices.Reverse(nums)

	if slices.Equal(arr, nums) {
		return temp
	}

	i := 0
	for i < len(nums) && nums[i] == arr[i] {
		i++
	}

	var j int
	for j = len(arr) - 1; j >= 0; j-- {
		if arr[j] == nums[i] {
			break
		}
	}

	arr[i], arr[j] = nums[i], arr[i]

	i = 0
	n := 0
	for i < len(nums) {
		n = n*10 + arr[i]
		i++
	}

	return n

}

func main() {

	fmt.Println(maximumSwap(9973))
}
