package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	leftDepth := maxDepth(root.Left)
	rightDepth := maxDepth(root.Right)

	if leftDepth > rightDepth {
		return leftDepth + 1
	} else {
		return rightDepth + 1
	}
}

func buildTree(nodes []interface{}) *TreeNode {
	if len(nodes) == 0 || nodes[0] == nil {
		return nil
	}

	rootVal, ok := nodes[0].(int)
	if !ok {
		return nil
	}
	root := &TreeNode{Val: rootVal}

	queue := []*TreeNode{root}
	i := 1

	for len(queue) > 0 && i < len(nodes) {
		currentNode := queue[0]
		queue = queue[1:]

		// Left child
		if i < len(nodes) && nodes[i] != nil {
			leftVal, ok := nodes[i].(int)
			if ok {
				currentNode.Left = &TreeNode{Val: leftVal}
				queue = append(queue, currentNode.Left)
			}
		}
		i++

		// Right child
		if i < len(nodes) && nodes[i] != nil {
			rightVal, ok := nodes[i].(int)
			if ok {
				currentNode.Right = &TreeNode{Val: rightVal}
				queue = append(queue, currentNode.Right)
			}
		}
		i++
	}
	return root
}

// func inorderTraversal(root *TreeNode) {
// 	if root == nil {
// 		return
// 	}
// 	inorderTraversal(root.Left)
// 	fmt.Printf("%d ", root.Val)
// 	inorderTraversal(root.Right)
// }

func main() {
	nodes := []interface{}{3, 9, 20, nil, nil, 15, 7}

	root := buildTree(nodes)

	fmt.Println(maxDepth(root))

}
