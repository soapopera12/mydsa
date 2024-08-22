# 145. Binary Tree Postorder Traversal
# https://leetcode.com/problems/binary-tree-postorder-traversal/description/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # left right root
        if not root:
            return []
        
        return self.postorderTraversal(root.left) + self.postorderTraversal(root.right) + [root.val]

        