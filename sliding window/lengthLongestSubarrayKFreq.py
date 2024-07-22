# 2958. Length of Longest Subarray With at Most K Frequency
# https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency

class Solution(object):
    def maxSubarrayLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        freq_dict = {}
        n = len(nums)
        left = 0
        maxi_subarr = 0

        for right in range(n):

            # 1. update current count of x in dict
            # we dont do the below thing to dict when initializing a new key 
            # freq_dict[nums[right]] += 1
            # freq_dict.get(what_you_want, default_value)
            freq_dict[nums[right]] = freq_dict.get(nums[right], 0) + 1

            # 3. if freq of x is more than k move left towards right till fixed
            while freq_dict[nums[right]] > k:
                freq_dict[nums[left]] -= 1
                left += 1

            # 2. Calculate maxi_subarr
            maxi_subarr = max(maxi_subarr, right - left + 1)

        return maxi_subarr
