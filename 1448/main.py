import math

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right




class Solution:
    

    def goodNodes(self, root: TreeNode) -> int:
       
        if not root:
            return 0

        self.count = 0

        self._dfs(root, -math.inf)
        
        return self.count

    def _dfs(self, node: TreeNode, max_val_so_far: int):
    
        if not node:
            return

        if node.val >= max_val_so_far:
            self.count += 1
        
        
        new_max_val_so_far = max(max_val_so_far, node.val)

        self._dfs(node.left, new_max_val_so_far)
        self._dfs(node.right, new_max_val_so_far)



root = TreeNode(1)
root.right = TreeNode(2)
root.left = TreeNode(2)
root.right.right=TreeNode(3)
root.right.left=TreeNode(4)

root.left.right=TreeNode(3)
root.left.left=TreeNode(4)

sol = Solution()
result = sol.goodNodes(root)

print(result)
