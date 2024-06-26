# 946. Validate Stack Sequences
# https://leetcode.com/problems/validate-stack-sequences

class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        # using a simple stack
        st = []
        j = 0

        for i in pushed:
            st.append(i)
            while st and st[-1] == popped[j]: # there is no top() method so to check last element we use -1
                st.pop()
                j += 1
            
        if st:
            return False
        
        return True
    
        