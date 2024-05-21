# 1614. Maximum Nesting Depth of the Parentheses
# https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses

class Solution:
    def maxDepth(self, s: str) -> int:
        # nesting dept of parantheses
        # you can always use a stack for parantheses
        count = 0
        max_count = 0
        for i in s:
            if i == "(":
                count += 1
                max_count = max(count, max_count)
            if i == ")":
                count -= 1
        return max_count
        # return max(accumulate(filter(None, map({"(": 1, ")": -1}.get, s))), default=0)
        # map({"(": 1, ")": -1}.get, s  ->  map the "(" in the string to 1 and ")" to -1 and return the string
        # remaining values are left as None so filter them out using filter method
        # accumulate will get the running total of the array here string




        