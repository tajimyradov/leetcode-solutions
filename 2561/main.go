package main

import (
	"fmt"
	"math"
	"sort"
)

func minCost(basket1 []int, basket2 []int) int64 {
	count := map[int]int{}
	m := math.MaxInt
	for _, v := range basket1 {
		count[v]++
		if v < m {
			m = v
		}
	}
	for _, v := range basket2 {
		count[v]--
		if v < m {
			m = v
		}
	}

	var arr []int
	for k, v := range count {
		if v%2 != 0 {
			return -1
		}
		for i := 0; i < absInt(v)/2; i++ {
			arr = append(arr, k)
		}
	}

	sort.Ints(arr)
	var res int64
	for i := 0; i < len(arr)/2; i++ {
		if 2*m < arr[i] {
			res += int64(2 * m)
		} else {
			res += int64(arr[i])
		}
	}
	return res
}

func absInt(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	fmt.Println(minCost([]int{4, 2, 2, 2}, []int{1, 4, 1, 2}))
	fmt.Println(minCost([]int{1, 1, 1, 1, 1}, []int{1, 1, 1, 1, 1}))
	fmt.Println(minCost([]int{1, 1, 1, 1, 1}, []int{1, 1, 1, 1, 1}))
}
