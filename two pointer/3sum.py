# 15. 3Sum
# https://leetcode.com/problems/3sum
 
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # oh here we go again
        # first sort
        target = 0
        nums.sort()
        s = set()  # because same set can be added twice by this function
        output = []

        for i in range(len(nums)):
            j = i + 1
            k = len(nums) - 1
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if sum == target:
                    s.add((nums[i], nums[j], nums[k]))
                    j += 1
                    k -= 1
                elif sum < target:   # simple AF
                    j += 1
                else:
                    k -= 1
        
        output = list(s)
        return output




        # nums.sort()
        # ans = []

        # lookup = map()
        # for i in range(len(nums)):
        #     lookup[nums[i]] = i # storing required index in the map
        
        # for i in range(len(nums)):
        #     current = nums[i]
        #     ptr = i + 1
        #     while ptr < len(nums):
        #         required = 0 - current - nums[ptr]
        #         if lookup[nums[required]]:
        #             ans.append(current, nums[ptr], nums[required])
            
        # return ans

                




        