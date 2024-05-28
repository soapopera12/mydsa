# 744. Find Smallest Letter Greater Than Target
# https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        # sorted in ascending order
        # find the first character that is greater than the target character
        # this will take O(n) how to do O(logn)
        # BST array

        if target >= letters[-1] or target < letters[0]:
            return letters[0]

        low = 0
        high = len(letters) - 1
        while low <= high:
            mid = (high+low)//2
            if target >= letters[mid]: # this will always keep the found element to left 1st element
                low = mid + 1
            
            if target < letters[mid]:
                high = mid - 1
            
        return letters[low]






        