# 844. Backspace String Compare
# https://leetcode.com/problems/backspace-string-compare/description/

class Solution(object):
    def backspaceCompare(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        def preprocess(string):
            result = []
            for char in string:
                if char != '#':
                    result.append(char)
                elif result:
                    result.pop()
            return result
        
        return preprocess(s) == preprocess(t)
        