from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self,root:TreeNode)->int:
        if root is None:
            return 0
        r1=self.dfs(root.left)
        r2=self.dfs(root.right)

        return max(r1,r2)+1

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        r1=self.dfs(root.left)
        r2=self.dfs(root.right)
        if  self.isBalanced(root.left) and self.isBalanced(root.right) and abs(r1-r2)<=1:
            return True
        return False



root = TreeNode(1)
root.right = TreeNode(2)
root.right.left = TreeNode(3)



sol = Solution()
result = sol.isBalanced(root)
print(result)