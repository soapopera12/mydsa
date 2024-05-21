# 108. Convert Sorted Array to Binary Search Tree
# https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if not nums:
            return None

        mid = len(nums) // 2

        root = TreeNode(nums[mid])           # given middle element 
        root.left = self.sortedArrayToBST(nums[:mid])        # better solution
        root.right = self.sortedArrayToBST(nums[mid+1:])     # even better

        return root
        # solution 2
        # def rec(nums, start, end):
        #     if start <= end:
        #         mid = (start + end) // 2
        #         node = TreeNode(nums[mid])
        #         node.left = rec(nums, start, mid-1)
        #         node.right = rec(nums, mid+1, end)
        #         return node
        
        # return rec(nums, 0, len(nums) - 1)