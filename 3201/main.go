package main

import "fmt"

type T struct {
	value int
	index int
}

func getRes(startWithEven bool, even, odd []T) []int {
	res := []int{}
	ei, oi := 0, 0
	lastIndex := -1
	useEven := startWithEven

	for {
		if useEven {
			for ei < len(even) && even[ei].index <= lastIndex {
				ei++
			}
			if ei == len(even) {
				break
			}
			res = append(res, even[ei].value)
			lastIndex = even[ei].index
			ei++
		} else {
			for oi < len(odd) && odd[oi].index <= lastIndex {
				oi++
			}
			if oi == len(odd) {
				break
			}
			res = append(res, odd[oi].value)
			lastIndex = odd[oi].index
			oi++
		}
		useEven = !useEven
	}

	return res
}

func maximumLength(nums []int) int {
	var even, odd []T
	for i, v := range nums {
		if v%2 == 0 {
			even = append(even, T{v, i})
		} else {
			odd = append(odd, T{v, i})
		}
	}

	maxLen := 0

	if len(even) > maxLen {
		maxLen = len(even)
	}

	if len(odd) > maxLen {
		maxLen = len(odd)
	}
	altEven := getRes(true, even, odd)
	if len(altEven) > maxLen {
		maxLen = len(altEven)
	}
	altOdd := getRes(false, even, odd)
	if len(altOdd) > maxLen {
		maxLen = len(altOdd)
	}

	return maxLen
}

func main() {
	nums := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52}
	res := maximumLength(nums)

	fmt.Println(res)
}
