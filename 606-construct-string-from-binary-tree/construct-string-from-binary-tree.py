# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def tree2str(self, root):
        ans = []
        self.dfs(root, ans)
        return ''.join(ans)
    def dfs(self, root, ans):
        if root is None:
            return

        ans.append(str(root.val))

        if root.left is None and root.right is None:
            return

        ans.append('(')
        self.dfs(root.left, ans)
        ans.append(')')

        if root.right is not None:
            ans.append('(')
            self.dfs(root.right, ans)
            ans.append(')')
        

    