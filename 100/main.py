from collections import deque
from typing  import Optional



class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def tree_to_level_order_array(self,root):
        if not root:
            return []

        result = []
        queue = deque([root])

        while queue:
            node = queue.popleft()
            if node:
                result.append(node.val)
                queue.append(node.left)
                queue.append(node.right)
            else:
                result.append(None)

        while result and result[-1] is None:
            result.pop()

        return result

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        
        return self.tree_to_level_order_array(q)==self.tree_to_level_order_array(p)



root = TreeNode(1)
root.right = TreeNode(2)
root.right.left = TreeNode(3)



sol = Solution()
result = sol.isSameTree(root,root)
print(result)
