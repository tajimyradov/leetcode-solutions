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

    
    
    def mirror(self, root: Optional[TreeNode]):
        if root is None:
            return
        
        self.mirror(root.left)
        self.mirror(root.right)

        temp = root.left
        root.left = root.right
        root.right = temp

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        res1=self.tree_to_level_order_array(root.left)
        self.mirror(root.right)
        res2=self.tree_to_level_order_array(root.right)
        return res1==res2



root = TreeNode(1)
root.right = TreeNode(2)
root.left = TreeNode(2)
# root.right.right=TreeNode(3)
# root.right.left=TreeNode(4)

# root.left.right=TreeNode(3)
# root.left.left=TreeNode(4)

sol = Solution()
result = sol.isSymmetric(root)
print(result)

