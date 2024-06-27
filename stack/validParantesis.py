# 20. Valid Parentheses
# https://leetcode.com/problems/valid-parentheses

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stk = []

        for i in s:
            if i in '([{':
                stk.append(i)
            else:
                if not stk or (i == ')' and stk[-1] != '(') or (i == '}' and stk[-1] != '{') or (i == ']' and stk[-1] != '['):
                    return False
                stk.pop()

        return not stk