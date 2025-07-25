package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func pathSum(root *TreeNode, targetSum int) int {
	if root == nil {
		return 0
	}
	return countFromNode(root, targetSum) + pathSum(root.Left, targetSum) + pathSum(root.Right, targetSum)
}

func countFromNode(node *TreeNode, targetSum int) int {
	if node == nil {
		return 0
	}
	count := 0
	if node.Val == targetSum {
		count = 1
	}
	count += countFromNode(node.Left, targetSum-node.Val)
	count += countFromNode(node.Right, targetSum-node.Val)
	return count
}

func main() {
	//[10,5,-3,3,2,null,11,3,-2,null,1]
	//answer is =3
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
	fmt.Println(pathSum(root, 8))

}
