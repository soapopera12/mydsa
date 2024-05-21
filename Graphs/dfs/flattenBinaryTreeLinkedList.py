# 114. Flatten Binary Tree to Linked List
# https://leetcode.com/problems/flatten-binary-tree-to-linked-list

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        # morris traversal
        curr = root 
        while curr:
            if curr.left:
                runner = curr.left      # finding the left node 
                while runner.right:     # go to the right most node of the left node
                    runner = runner.right
                runner.right = curr.right   # update the position of each node
                curr.right = curr.left
                curr.left = None
            curr = curr.right            # continue on to right side