# 540. Single Element in a Sorted Array
# https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        right = len(nums) - 1
        # nums must be odd number
        # so you may assume the mid element is even
        # But still the mid element could be an odd number
        # So we multiply middle element by 2 to keep it even
        
        while left < right:
            # pivot element must be even
            mid = 2 * ((left + right) // 4)

            if nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1]:
                return nums[mid]
            elif nums[mid] == nums[mid+1]:
                # continue on right side
                left = mid + 2
            else:
                right = mid
            
        return nums[left]





        