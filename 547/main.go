package main

import "fmt"

func findCircleNum(isConnected [][]int) int {
	visit := make([]bool, len(isConnected))
	num := 0

	var dfs func(n int, isConnected [][]int, visit []bool)
	dfs = func(n int, isConnected [][]int, visit []bool) {
		visit[n] = true
		for j := range isConnected {
			if isConnected[n][j] == 1 && !visit[j] {
				dfs(j, isConnected, visit)
			}
		}
	}
	for i := range isConnected {
		if !visit[i] {
			num++
			dfs(i, isConnected, visit)
		}
	}

	return num
}

func main() {
	input := [][]int{
		{1, 1, 0},
		{1, 1, 0},
		{0, 0, 1},
	}

	fmt.Println(findCircleNum(input))
}
