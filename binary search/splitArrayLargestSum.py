# 410. Split Array Largest Sum
# https://leetcode.com/problems/split-array-largest-sum

class Solution(object):
    def splitArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        low = max(nums)
        high = sum(nums)

        while low < high: # dont include = when you want to exit at low == high -> done to find the case of perfectly choosing atleast one element

            mid = (low + high) // 2

            tot_sum, splits = 0, 1 # current splits are 1

            for num in nums:

                if num + tot_sum > mid:
                    tot_sum = num
                    splits += 1
                else:
                    tot_sum += num
            
            if splits > k:
                # find a bigger sum to split the array
                low = mid + 1
            else:
                high = mid
            
        return high

