package main

import (
	"fmt"
)

func minTimeToVisitAllPoints(points [][]int) int {
	totalTime := 0
	for i := 0; i < len(points)-1; i++ {
		x1, y1 := points[i][0], points[i][1]
		x2, y2 := points[i+1][0], points[i+1][1]
		dx := x2 - x1
		dy := y2 - y1
		if dx < 0 {
			dx = -dx
		}
		if dy < 0 {
			dy = -dy
		}

		totalTime += max(dx, dy)
	}
	return totalTime
}

func main() {
	fmt.Print(minTimeToVisitAllPoints([][]int{
		{1, 1},
		{3, 4},
		{-1, 0},
	}))
}
