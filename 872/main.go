package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
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

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	leaves1 := collectLeaves(root1)
	leaves2 := collectLeaves(root2)

	if len(leaves1) != len(leaves2) {
		return false
	}

	for i := 0; i < len(leaves1); i++ {
		if leaves1[i] != leaves2[i] {
			return false
		}
	}
	return true
}

func collectLeaves(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}

	if root.Left == nil && root.Right == nil {
		return []int{root.Val}
	}

	leftLeaves := collectLeaves(root.Left)
	rightLeaves := collectLeaves(root.Right)

	return append(leftLeaves, rightLeaves...)

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
	nodes1 := []interface{}{3, 5, 1, 6, 2, 9, 8, nil, nil, 7, 4}
	nodes2 := []interface{}{3, 5, 1, 6, 7, 4, 2, nil, nil, nil, nil, nil, nil, 9, 8}

	root1 := buildTree(nodes1)
	root2 := buildTree(nodes2)

	fmt.Println(leafSimilar(root1, root2))
}
