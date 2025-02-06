# 2140. Solving Questions With Brainpower
# https://leetcode.com/problems/solving-questions-with-brainpower/

class Solution(object):
    def mostPoints(self, questions):
        """
        :type questions: List[List[int]]
        :rtype: int
        """
        n = len(questions)

        # one extra to keep a zero and not miss the last question
        dp = [0 for i in range(n + 1)]

        for i in range(n - 1, -1, -1):
            # from last question to first question
            # if you want to take the points for this question 
            # you should calculate the points it gives till i
            points, brain_power = questions[i]

            current = points + dp[min(i+brain_power+1, n)]

            # also considering the case you do not take
            dp[i] = max(current, dp[i+1])

        return dp[0]



# class Solution(object):
#     def mostPoints(self, questions):
#         """
#         :type questions: List[List[int]]
#         :rtype: int
#         """
#         def solve(i):

#             if i >= len(questions):
#                 return 0

#             if dp[i] != -1:
#                 return dp[i]
            
#             # take condition
#             take = questions[i][0] + solve(i + questions[i][1] + 1)

#             # not take condition
#             not_take = solve(i + 1)

#             dp[i] = max(take, not_take)
#             return dp[i]
            
#         dp = [-1] * len(questions)

#         return solve(0)

          
