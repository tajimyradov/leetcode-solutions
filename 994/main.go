package main

import "fmt"

func orangesRotting(grid [][]int) int {
	dirs := [][2]int{
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1},
	}

	queue := make([][2]int, 0)
	count := 0

	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == 2 {
				queue = append(queue, [2]int{i, j})
			}
			if grid[i][j] == 1 {
				count++
			}
		}
	}

	if count == 0 {
		return 0
	}

	time := 0
	for len(queue) > 0 {
		size := len(queue)
		for i := 0; i < size; i++ {
			curr := queue[0]
			queue = queue[1:]

			for _, dir := range dirs {
				newRow := curr[0] + dir[0]
				newCol := curr[1] + dir[1]

				if newRow >= 0 && newRow < len(grid) && newCol >= 0 && newCol < len(grid[0]) && grid[newRow][newCol] == 1 {
					grid[newRow][newCol] = 2
					queue = append(queue, [2]int{newRow, newCol})
					count--
				}
			}
		}
		time++
	}

	if count > 0 {
		return -1
	}

	return time - 1
}

func main() {
	grid := [][]int{
		{2, 1, 1},
		{1, 1, 0},
		{0, 1, 1},
	}
	result := orangesRotting(grid)
	fmt.Println(result)
}
