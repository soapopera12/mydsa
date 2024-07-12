# 402. Remove K Digits
# https://leetcode.com/problems/remove-k-digits/description/

class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        # fill the stack in reverse order 
        # pop the tos and store it if it is greater than current tos delete it or pop current element
        # continue
        
        stk = []
        ans = ""
        
        for i in num:
            while k > 0 and stk and i < stk[-1]:
                stk.pop()
                k -= 1
            stk.append(i)

        while k > 0 and stk:
            stk.pop()
            k -= 1
        
        temp = ""

        for c in stk:
            if not ans and c == '0':
                continue
            ans += c
        
        return ans if ans else '0'



        