package main

import "fmt"

func minCostClimbingStairs(cost []int) int {

	dp0 := 0
	dp1 := 0
	for i := 2; i <= len(cost); i++ {
		dp := min(dp1+cost[i-1], dp0+cost[i-2])
		dp0 = dp1
		dp1 = dp
	}
	return dp1
}

func main() {
	costs := []int{1, 100, 1, 1, 1, 100, 1, 1, 100, 1}

	fmt.Println(minCostClimbingStairs(costs))
}
