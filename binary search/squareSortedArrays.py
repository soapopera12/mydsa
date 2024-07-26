# 977. Squares of a Sorted Array
# https://leetcode.com/problems/squares-of-a-sorted-array

class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        ans = [0] * n

        # two pointer approach is best
        # because the array is sorted 
        # after sqaring in becomes something like a reverse of 
        # a bitonic array -> reduces than starts increasing
        left = 0
        right = n - 1
        lastPointer = right

        while left <= right:
            if abs(nums[left]) > abs(nums[right]):
                ans[lastPointer] = nums[left] ** 2
                left += 1
            else:
                ans[lastPointer] = nums[right] ** 2
                right -= 1
            lastPointer -= 1

        return ans


        
        