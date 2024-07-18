# 658. Find K Closest Elements 
# https://leetcode.com/problems/find-k-closest-elements/description/

class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        # https://www.youtube.com/watch?v=o-YDQzHoaKM
        # basically we use binary search and assume if we start from mid then k elements are the actual elements closest to x
        # now we eliminate either the left part or the right part based on the fact as follows
        # we can assume our window may be to the right but then the element just outside the window k to the right must be more closer to x
        # because that is the only case that we move our window right so we change left to mid + 1
        # other wise our window could be current window or to the left so we change right to mid
        # Remember x may not be present in the array
        l, r = 0 , len(arr) - k

        while l < r:
            m = (l + r) // 2
            if x - arr[m] > arr[m+k] - x:  # this basically check if m is closer to x or otherwise
                l = m + 1       # if x is closer to arr[m+k] then we can say with 100% guarantee that x will lie to the right
            else:
                r = m           # otherwise if x is closer to arr[m] then we can say with 100% guarantee that x will lie to the left

        return arr[l:l+k]
