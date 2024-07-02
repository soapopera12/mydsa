# 2390. Removing Stars From a String
# https://leetcode.com/problems/removing-stars-from-a-string/

class Solution(object):
    def removeStars(self, s):
        """
        :type s: str
        :rtype: str
        """
        stk = []

        for i in s:
            if stk and i == '*':
                stk.pop(-1)
            else:
                stk.append(i)
        
        return ''.join(stk)
            

        