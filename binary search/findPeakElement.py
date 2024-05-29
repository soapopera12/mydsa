# 162. Find Peak Element
# https://leetcode.com/problems/find-peak-element

class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # The question is to find the peak element here 
        # you can get the solution in linear time 
        # also binary search can be utilized to get the solution in log(n) time
        

        # linear time
        # for i in range(len(nums)-1):
        #     if nums[i] > nums[i-1] and nums[i] > nums[i+1]:
        #         return i
        
        # return len(nums) - 1

        # binary search method to get log(n)
        n = len(nums)
        low, high = 0, n-1
        while low<=high:
            mid = (((high - low)) // 2) + low
            # peak element is present in right side
            if mid < n - 1 and nums[mid] < nums[mid+1]:
                low = mid + 1
            # peak element is present in left side
            elif mid > 0 and nums[mid] < nums[mid-1]:
                high = mid - 1
            else:
                return mid


        
        