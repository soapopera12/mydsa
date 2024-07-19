# 1838. Frequency of the Most Frequent Element
# https://leetcode.com/problems/frequency-of-the-most-frequent-element/

class Solution(object):
    def maxFrequency(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # maybe first sort nums
        nums.sort()

        maxi_freqy = 0
        currentSum = 0

        lefty = 0

        for righty in range(len(nums)):
            currentSum += nums[righty]

            # checkin if we will be able to make all element
            # equal to the biggest element in the sliding window
            while currentSum + k < nums[righty] * (righty - lefty + 1):
                currentSum -= nums[lefty]
                lefty += 1
            
            maxi_freqy = max(righty - lefty + 1, maxi_freqy)
        
        return maxi_freqy

