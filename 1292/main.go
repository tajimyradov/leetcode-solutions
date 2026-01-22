package main

import "fmt"

func maxSideLength(mat [][]int, threshold int) int {
	m, n := len(mat), len(mat[0])
	prefixSum := make([][]int, m+1)
	for i := range prefixSum {
		prefixSum[i] = make([]int, n+1)
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			prefixSum[i][j] = mat[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1]
		}
	}

	canFit := func(size int) bool {
		for i := size; i <= m; i++ {
			for j := size; j <= n; j++ {
				sum := prefixSum[i][j] - prefixSum[i-size][j] - prefixSum[i][j-size] + prefixSum[i-size][j-size]
				if sum <= threshold {
					return true
				}
			}
		}
		return false
	}

	left, right := 0, min(m, n)
	result := 0
	for left <= right {
		mid := (left + right) / 2
		if canFit(mid) {
			result = mid
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return result
}

func main() {
	fmt.Println(maxSideLength([][]int{
		{3, 2, 4, 3, 2, 1, 1},
		{3, 2, 4, 3, 2, 1, 1},
		{3, 2, 4, 3, 2, 1, 1},
	}, 4))
}
