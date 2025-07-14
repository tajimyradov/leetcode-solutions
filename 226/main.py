from collections import deque
from typing  import Optional



class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    
    def mirror(self, root: Optional[TreeNode]):
        if root is None:
            return
        
        self.mirror(root.left)
        self.mirror(root.right)

        temp = root.left
        root.left = root.right
        root.right = temp

    
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.mirror(root)
        return root

root = TreeNode(1)
root.right = TreeNode(2)
root.left = TreeNode(2)
# root.right.right=TreeNode(3)
# root.right.left=TreeNode(4)

# root.left.right=TreeNode(3)
# root.left.left=TreeNode(4)

sol = Solution()
result = sol.invertTree(root)

