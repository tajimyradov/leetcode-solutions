
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        i=0

        while ( head is not None):
            i=i*2+head.val
            head=head.next
        return i


head=ListNode(1)
head.next=ListNode(0)
head.next.next=ListNode(1)

sol=Solution()
print(sol.getDecimalValue(head))