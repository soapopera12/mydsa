# 101. Symmetric Tree
# https://leetcode.com/problems/symmetric-tree
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def symmetericTest(self, left, right):
        if not left and not right:
            return True
        if not left or not right:
            return False
        return left.val == right.val and self.symmetericTest(left.left, right.right) and self.symmetericTest(left.right, right.left)

    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # can always do BFS ans check one from left and one from right
        if not root:
            return True
        
        return self.symmetericTest(root.left, root.right)

        