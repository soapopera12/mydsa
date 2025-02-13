# 416. Partition Equal Subset Sum
# https://leetcode.com/problems/partition-equal-subset-sum/

# bottom-up
class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        total = sum(nums)
        if total % 2 == 1: return False
        target = total//2
        dp = [False]*(target+1)
        dp[0] = True
        for num in nums:
            for val in range(target,num-1,-1):
                dp[val] = dp[val] or dp[val-num]
        return dp[-1]
        
        

# top down memoization  
# class Solution(object):
#     def canPartition(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: bool
#         """

#         def solve(summy, i):
#             if summy == 0:
#                 return True
#             if summy < 0:
#                 return False
            
#             if i == len(nums):
#                 return False
            
#             if (i, summy) in memo:
#                 return memo[(i, summy)]
            
#             take = solve(summy - nums[i], i + 1)
#             not_take = solve(summy, i + 1)
#             memo[(i, summy)] = take | not_take
#             return memo[(i, summy)]

        
#         total_sum = sum(nums)

#         if total_sum % 2 != 0:
#             return False
        
#         target_sum = total_sum // 2
    
#         memo = {}

#         return solve(target_sum, 0)

        



