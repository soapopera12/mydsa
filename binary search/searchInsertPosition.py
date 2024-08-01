class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left = 0
        right = len(nums) - 1

        while left <= right:

            mid = (left + right) / 2

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1   # left always goes one index ahead
            else:
                right = mid - 1
                
        # return left becuase it is just one index higher than the eleemnt just smaller to target
        return left 


        