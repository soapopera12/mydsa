# 71. Simplify Path
# https://leetcode.com/problems/simplify-path

class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        # split strings at / 
        stk = []
        split_string = path.split('/')
        for i in split_string:
            if i == '..':
                if stk:
                    stk.pop()
                else:
                    continue
            elif i == '.' or not i:
                continue
            else:
                stk.append(i)
            
        return '/' +'/'.join(stk)
        