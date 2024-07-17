# 2962. Count Subarrays Where Max Element Appears at Least K Times    
# https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times

class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # step 1. Find the maximum number and all the indices it is present
        maxi = max(nums) # maxi
        l = 0           # left pointer
        c = 0           # occurences of maxi
        ans = 0         # total subarrays

        # step 2. Find all subarray
        for num in nums:
            if num == maxi:
                c += 1                  # is maxi incrent occurences
            while c >= k:               # if occurence is greater than equal to k
                if nums[l] == maxi:     
                    c -= 1      
                l += 1                  # increasing left pointer and if it is maxi decrasing occurences
            ans += l                    # increasing ans by l till occurences is now less than k
                                        # this works because if current window is valid adding 
                                        # one element from the left side will give corrent answer itself
                                        # this is only for subarray
        
        return ans
        
    





        