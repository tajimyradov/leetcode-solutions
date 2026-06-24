package main

import "fmt"

func nearestExit(maze [][]byte, entrance []int) int {
	rows, cols := len(maze), len(maze[0])

	type Node struct {
		r, c  int
		steps int
	}

	queue := []Node{{entrance[0], entrance[1], 0}}
	maze[entrance[0]][entrance[1]] = '+'

	dirs := [][2]int{
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1},
	}

	for len(queue) > 0 {
		cur := queue[0]
		queue = queue[1:]

		if (cur.r != entrance[0] || cur.c != entrance[1]) &&
			(cur.r == 0 || cur.c == 0 ||
				cur.r == rows-1 || cur.c == cols-1) {
			return cur.steps
		}

		for _, d := range dirs {
			nr := cur.r + d[0]
			nc := cur.c + d[1]

			if nr >= 0 && nr < rows &&
				nc >= 0 && nc < cols &&
				maze[nr][nc] == '.' {

				maze[nr][nc] = '+'
				queue = append(queue, Node{nr, nc, cur.steps + 1})
			}
		}
	}

	return -1
}
func main() {
	// Example usage:
	maze := [][]byte{
		{'+', '+', '.', '+'},
		{'.', '.', '.', '+'},
		{'+', '+', '+', '.'},
	}
	entrance := []int{1, 2}
	result := nearestExit(maze, entrance)
	fmt.Println(result) // Output: 1
}
