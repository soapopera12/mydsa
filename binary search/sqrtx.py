# 69. Sqrt(x)
# https://leetcode.com/problems/sqrtx

class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        # binary search between 0 and x
        left = 0
        right = x

        while left <= right:
            
            mid = (left + right) // 2

            if mid ** 2 > x:
                right = mid - 1
            else:
                left = mid + 1 # finding the number that is just 1 bigger than answer
            
        return left - 1

        