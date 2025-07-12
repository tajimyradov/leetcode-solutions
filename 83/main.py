from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        new_head = ListNode(head.val)
        temp = new_head
        while head is not None:
            if temp.val != head.val:
                temp.next = ListNode(head.val)
                temp = temp.next
            head = head.next
        return new_head



head = ListNode(1)
head.next = ListNode(1)
head.next.next = ListNode(2)
head.next.next.next = ListNode(3)
head.next.next.next.next = ListNode(3)
head.next.next.next.next.next = ListNode(3)
head.next.next.next.next.next.next = ListNode(4)

solution = Solution()

result_head = solution.deleteDuplicates(head)

def print_linked_list(node: Optional[ListNode]):
    current = node
    while current:
        print(current.val, end=" -> " if current.next else "")
        current = current.next
    print()

print_linked_list(head)

print_linked_list(result_head)