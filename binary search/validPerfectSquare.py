# 367. Valid Perfect Square
# https://leetcode.com/problems/valid-perfect-square/

class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """

        # given a num is it a perfect square or not
        # has to be a square of some number
        if num < 0:
            return False

        l = 0
        r = num

        while l <= r:
            mid = ( l + r ) / 2

            if mid ** 2 == num:
                return True
            elif mid ** 2 > num:
                r = mid - 1
            elif mid * mid < num:
                l = mid + 1

        return False   
            