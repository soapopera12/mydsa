# 605. Can Place Flowers
# https://leetcode.com/problems/can-place-flowers/description/

class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        if n == 0:
            return True

        for i in range(len(flowerbed)):
            if flowerbed[i] == 0 and (i == 0 or flowerbed[i-1] == 0) and (i == len(flowerbed)-1 or flowerbed[i+1] == 0):                # both neighbors are not adjacent
                flowerbed[i] = 1    
                n -= 1
                if n == 0:
                    return True
        
        return False
        