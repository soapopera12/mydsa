# 215. Kth Largest Element in an Array
# https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        hp = []
        # add each elemnent to hp
        for num in nums:
            # push element to leaf place swap with parent node till heap is mantained
            heapq.heappush(hp, num)
            
        # fing len(nums) - k and pop them from hp
        for _ in range(len(nums) - k):
            heapq.heappop(hp)
        
        return heapq.heappop(hp)

