# 2300. Successful Pairs of Spells and Potions
# https://leetcode.com/problems/successful-pairs-of-spells-and-potions

class Solution(object):
    def successfulPairs(self, spells, potions, success):
        """
        :type spells: List[int]
        :type potions: List[int]
        :type success: int
        :rtype: List[int]
        """
        # sort potions
        #spells.sort()
        potions.sort()

        # product of spell[i] * potions[j] >= success
        ans = [0] * len(spells)

        # binary search to find smalles element in potions where product is >= success
        for i in range(len(spells)):
            left = 0
            right = len(potions) - 1

            while left <= right:
                mid = left + (right - left) // 2   # correct way of finding mid

                if spells[i] * potions[mid] < success:
                    left = mid + 1
                else:
                    right = mid - 1        # because mid can also be the answer
            
            ans[i] = len(potions) - left
        
        return ans
            



 

        

        