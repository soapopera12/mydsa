# 554. Brick Wall
# https://leetcode.com/problems/brick-wall

class Solution(object):
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        # Calculate every edge position and stpre it in a separe matrix
        edge_frequency = {}
        max_frequency = 0

        for row in range(len(wall)):
            edge_postion = 0
            for brick_no in range(len(wall[row])-1):
                current_brick_length = wall[row][brick_no]
                edge_postion = edge_postion + current_brick_length
                edge_frequency[edge_postion] = edge_frequency.get(edge_postion,0) + 1
                max_frequency = max(edge_frequency[edge_postion], max_frequency)

        return len(wall) - max_frequency

        