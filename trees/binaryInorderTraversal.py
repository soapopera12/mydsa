# 94. Binary Tree Inorder Traversal
# https://leetcode.com/problems/binary-tree-inorder-traversal

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # left root right

        if not root:
            return []

        ans = []

        # go left
        ans += self.inorderTraversal(root.left)
        # append current
        ans.append( root.val)
        # go right
        ans += self.inorderTraversal(root.right)

        return ans