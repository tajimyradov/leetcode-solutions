package main

import (
	"container/list"
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxLevelSum(root *TreeNode) int {
	queue := list.New()
	queue.PushBack(root)
	level := 1
	levelSum := 0
	maxLevel := 1
	maxSum := root.Val

	for queue.Len() > 0 {
		levelSize := queue.Len()
		for i := 0; i < levelSize; i++ {
			node := queue.Front()
			queue.Remove(node)
			levelSum += node.Value.(*TreeNode).Val

			if node.Value.(*TreeNode).Left != nil {
				queue.PushBack(node.Value.(*TreeNode).Left)
			}

			if node.Value.(*TreeNode).Right != nil {
				queue.PushBack(node.Value.(*TreeNode).Right)
			}
		}

		if levelSum > maxSum {
			maxSum = levelSum
			maxLevel = level
		}
		levelSum = 0
		level++
	}

	return maxLevel
}

func main() {
	root := &TreeNode{
		Val: 1,
		Left: &TreeNode{
			Val: 2,
		},
		Right: &TreeNode{
			Val: 3,
		},
	}

	fmt.Println(maxLevelSum(root))
}
