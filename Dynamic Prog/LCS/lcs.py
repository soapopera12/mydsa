# 1143. Longest Common Subsequence
# https://leetcode.com/problems/longest-common-subsequence/description/

class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        n, m = len(text1), len(text2)
        
        dp = [[0] * (m+1) for _ in range(n+1)]

        for i in range(1, n + 1):
            for j in range(1, m+ 1):

                if text1[i-1] == text2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

        return dp[n][m]


# memoization | top-down solution
# class Solution(object):
#     def longestCommonSubsequence(self, text1, text2):
#         """
#         :type text1: str
#         :type text2: str
#         :rtype: int
#         """
#         n, m = len(text1), len(text2)
        
#         dp = [[-1] * m for _ in range(n)]

#         def solve(i, j):

#             if i >= n or j >= m:
#                 return 0

#             if dp[i][j] != -1:
#                 return dp[i][j]

#             ans = 0

#             if text1[i] == text2[j]:
#                 # characters match 
#                 ans += 1 + solve(i + 1, j + 1)
#             else:
#                 # characters don't match 
#                 ans = max(solve(i + 1, j), solve(i, j + 1))

#             dp[i][j] = ans
            
#             return ans

#         return solve(0, 0)



# recursion solution
# def longestCommonSubsequence(self, text1, text2):
#         """
#         :type text1: str
#         :type text2: str
#         :rtype: int
#         """
#         n, m = len(text1), len(text2)

#         def solve(i, j):

#             if i >= n or j >= m:
#                 return 0

#             ans = 0

#             if text1[i] == text2[j]:
#                 # characters match 
#                 ans += 1 + solve(i + 1, j + 1)
#             else:
#                 # characters don't match 
#                 ans = max(solve(i + 1, j), solve(i, j + 1))

#             return ans

#         return solve(0, 0)


