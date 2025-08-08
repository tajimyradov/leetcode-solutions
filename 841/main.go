package main

import "fmt"

func canVisitAllRooms(rooms [][]int) bool {
	visited := make([]bool, len(rooms))

	var dfs func(int)
	dfs = func(room int) {
		if visited[room] {
			return
		}
		visited[room] = true
		for _, key := range rooms[room] {
			dfs(key)
		}
	}

	dfs(0)

	for _, v := range visited {
		if !v {
			return false
		}
	}
	return true
}

func main() {
	rooms := [][]int{
		{1},
		{2},
		{3},
		{},
	}

	fmt.Println(canVisitAllRooms(rooms))

}
