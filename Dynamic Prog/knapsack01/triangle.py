# 120. Triangle
# https://leetcode.com/problems/triangle/description/


class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        n = len(triangle)

        dp = [[-1] * n for i in range(n)]

        dp[n-1] = triangle[n-1]

        # do not processes the last layer
        for i in range(n-2, -1, -1):
            for j in range(i+1):
                # each element has two option
                left = triangle[i][j] + dp[i+1][j]
                right = triangle[i][j] + dp[i+1][j+1]
                dp[i][j] = min(left, right)

        return dp[0][0]     
        


# class Solution(object):
#     def minimumTotal(self, triangle):
#         """
#         :type triangle: List[List[int]]
#         :rtype: int
#         """

#         total_rows = len(triangle)
#         # simple 01 knapsack
#         def solve(row, column):

#             if row+1 >= total_rows:
#                 return 0
            
#             if dp[row][column] != -1:
#                 return dp[row][column]
#             # two options
#             # [row+1][col] or [row+1][col+1]

#             left = triangle[row+1][column] + solve(row+1, column)
#             right = triangle[row+1][column+1] + solve(row+1, column+1)
lask==2.1.1
xgboost==1.6.0
pandas==1.4.2
numpy==1.23.1
scikit-learn==0.24.2
gunicorn==20.1.0  # If you're using gunicorn for production


#             dp[row][column] = min(right, left)
            
#             return min(right, left)

#         dp = [[-1] * len(triangle[-1]) for i in range(1, total_rows)]
#         minimal_sum = triangle[0][0] + solve(0, 0)

#         return minimal_sum
        
