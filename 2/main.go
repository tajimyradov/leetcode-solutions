package main

import "log"

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	result := &ListNode{Val: 0}
	curr := result
	var m int
	var ll1, ll2 int
	for l1 != nil || l2 != nil || m != 0 {
		ll1 = 0
		if l1 != nil {
			ll1 = l1.Val
		}
		ll2 = 0
		if l2 != nil {
			ll2 = l2.Val
		}

		curr.Next = &ListNode{Val: (ll1 + ll2 + m) % 10}
		curr = curr.Next

		m = (ll1 + ll2 + m) / 10

		if l1 != nil {
			l1 = l1.Next
		}

		if l2 != nil {
			l2 = l2.Next
		}

	}

	return result.Next
}

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	log.Println(addTwoNumbers(&ListNode{Val: 1}, &ListNode{Val: 1}))
}
