# 938. Range Sum of BST
# https://leetcode.com/problems/range-sum-of-bst

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rangeSumBST(self, root, low, high):
        """
        :type root: TreeNode
        :type low: int
        :type high: int
        :rtype: int
        """
        # when node.val is in low and high add those values and return the sum
        if not root:
            return 0

        ans = root.val if low <= root.val <= high else 0

        return  self.rangeSumBST(root.left, low, high) + self.rangeSumBST(root.right, low, high) + ans



        