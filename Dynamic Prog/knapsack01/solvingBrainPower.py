# 2140. Solving Questions With Brainpower
# https://leetcode.com/problems/solving-questions-with-brainpower/description/

class Solution(object):

    def mostPoints(self, questions):
        """
        :type questions: List[List[int]]
        :rtype: int
        """

        def solve(i):

            if i >= len(questions):
                return 0

            if dp[i] != -1:
                return dp[i]
            
            # take condition
            take = questions[i][0] + solve(i + questions[i][1] + 1)

            # not take condition
            not_take = solve(i + 1)

            dp[i] = max(take, not_take)
            return dp[i]
            
        dp = [-1] * len(questions)

        return solve(0)
        
