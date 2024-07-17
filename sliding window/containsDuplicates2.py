# 219. Contains Duplicate II
# https://leetcode.com/problems/contains-duplicate-ii

class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        # Store indices in dict
        duplicate_dict = {}

        for i, v in enumerate(nums):
            if v in duplicate_dict and i - duplicate_dict[v] <= k:
                return True
            duplicate_dict[v] = i
        
        return False

        # 1 2 3 1

        