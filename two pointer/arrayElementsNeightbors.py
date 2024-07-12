# 1968. Array With Elements Not Equal to Average of Neighbors
# https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

class Solution(object):
    def rearrangeArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # Don't keey any asceding or descending order

        for i in range(len(nums)-1):
            if nums[i-1] < nums[i] and nums[i] < nums[i+1]:
                temp = nums[i+1]
                nums[i+1] = nums[i]
                nums[i] = temp
            elif nums[i-1] > nums[i] and nums[i] > nums[i+1]:
                temp = nums[i+1]
                nums[i+1] = nums[i]
                nums[i] = temp
        
        return nums