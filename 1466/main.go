package main

import "fmt"

func minReorder(n int, connections [][]int) int {
	result := 0

	graph := make(map[int][][]int)
	for _, conn := range connections {
		from, to := conn[0], conn[1]
		graph[from] = append(graph[from], []int{to, 1})
		graph[to] = append(graph[to], []int{from, 0})
	}

	visited := make([]bool, n)
	var dfs func(int)
	dfs = func(node int) {
		visited[node] = true
		for _, neighbor := range graph[node] {
			nextNode, needsReorder := neighbor[0], neighbor[1]
			if !visited[nextNode] {
				result += needsReorder
				dfs(nextNode)
			}
		}
	}

	dfs(0)

	return result
}

func main() {
	fmt.Println(minReorder(6, [][]int{
		{0, 1},
		{1, 3},
		{2, 3},
		{4, 0},
		{4, 5},
	}))

}
