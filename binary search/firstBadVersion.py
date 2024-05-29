# 278. First Bad Version
# https://leetcode.com/problems/first-bad-version

# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        # some what like peak element
        # implement plain binary search here

        left = 1
        right = n - 1

        while left <= right:
            middle = ((right - left) / 2) + left
            if isBadVersion(middle):   # this will run till we exhaust the search 
                # go left - already passed the first bad product
                right = middle - 1  
            else:
                # go right
                left = middle + 1

        return left 