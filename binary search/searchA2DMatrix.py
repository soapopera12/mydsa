# 74. Search a 2D Matrix
# https://leetcode.com/problems/search-a-2d-matrix

class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        # visualize the matrix as a single list

        left = 0
        m = len(matrix)
        n = len(matrix[0])
        right = m * n - 1

        while left <= right:
            mid = (left + right) / 2

            if matrix[mid / n][mid % n] == target:
                return True
            elif matrix[mid / n][mid % n] > target:
                right = mid - 1
            else:
                left = mid + 1
            
        return False





