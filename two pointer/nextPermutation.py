# 31. Next Permutation
# https://leetcode.com/problems/next-permutation

class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k, l = n-2, n-1

        #  finds the first pair of adjacent elements in the array that 
        # satisfy nums[k] < nums[k+1] from the right end of the array.
        while k >= 0 and nums[k] >= nums[k + 1]:
            k -= 1

        if k < 0:
            # such a pair does not exist, then the entire array is sorted in descending order
            nums.reverse()
        else:
            # finds the smallest element nums[l] to the right of nums[k] such that 
            # nums[l] > nums[k]. We swap nums[k] and nums[l], and then reverse the 
            # subarray starting at nums[k+1] to obtain the next lexicographic permutation 
            # of the array
            while l > k and nums[l] <= nums[k]:
                l -= 1
            nums[k], nums[l] = nums[l], nums[k]
            nums[k + 1:n] = reversed(nums[k + 1:n])
