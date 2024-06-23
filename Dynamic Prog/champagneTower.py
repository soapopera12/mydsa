# 799. Champagne Tower
# https://leetcode.com/problems/champagne-tower

class Solution(object):
    def champagneTower(self, poured, query_row, query_glass):
        """
        :type poured: int
        :type query_row: int
        :type query_glass: int
        :rtype: float
        """
        # make an array that stores the amount of champange in a pyramid type form
        tower = [[0] * (i + 1) for i in range(query_row + 1)]
        tower[0][0] = poured
        
        for row in range(query_row):
            # for each row in the champange pyramid
            for glass in range(len(tower[row])):
                # for each glass in the current row of the champange pyramid
                # why this works
                # becasue we are calculating the excess in the glass and then calculating what
                # half of the excess is for the next two glasses
                # and we keep doing this 
                excess = (tower[row][glass] - 1)/ 2.0
                if excess > 0:
                    tower[row+1][glass] += excess # for down-left glass
                    tower[row+1][glass + 1] += excess # for down-right glass

        return min(1.0, tower[query_row][query_glass])
        
        # Champagne tower
        # After pouring poured number of cups in the champagne tower
        # for 1 cup -> 1st row full cup
        # for 2 cup -> 1st row full, 2nd row half
        # for 3 cup -> 1st row full, 2nd row full
        # for 4 cup -> 1st row full, 2nd row full, 3rd row [outside cups 1/4], [inside cup 1/2]  
        # for 5 cups -> 1st row full, 2nd row full, 3rd row [outside cups 1/2], [inside cup full]
        # after 2 rows -> each row n has n - 1 inner cups

        

