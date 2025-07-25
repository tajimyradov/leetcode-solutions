package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func longestZigZag(root *TreeNode) int {
	maxLen := 0
	var dfs func(node *TreeNode) (left, right int)
	dfs = func(node *TreeNode) (left, right int) {
		if node == nil {
			return -1, -1
		}
		_, lRight := dfs(node.Left)
		rLeft, _ := dfs(node.Right)
		left = lRight + 1
		right = rLeft + 1
		if left > maxLen {
			maxLen = left
		}
		if right > maxLen {
			maxLen = right
		}
		return
	}
	dfs(root)
	return maxLen
}

func main() {
	root := &TreeNode{
		Val: 10,
		Left: &TreeNode{
			Val: 5,
			Left: &TreeNode{
				Val: 3,
				Left: &TreeNode{
					Val: 3,
				},
				Right: &TreeNode{
					Val: -2,
				},
			},
			Right: &TreeNode{
				Val: 2,
				Right: &TreeNode{
					Val: 1,
				},
			},
		},
		Right: &TreeNode{
			Val: -3,
			Right: &TreeNode{
				Val: 11,
			},
		},
	}
	fmt.Println(longestZigZag(root))
}
