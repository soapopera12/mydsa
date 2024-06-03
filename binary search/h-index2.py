# 275. H-Index II
# https://leetcode.com/problems/h-index-ii

class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        left = 0
        right = n - 1

        while left <= right:
            middle = (left + right) // 2 
            noOfPapers = n - middle
            if noOfPapers <= citations[middle]:
                right = middle - 1
            else:
                left = middle + 1
        
        return n-left
             
