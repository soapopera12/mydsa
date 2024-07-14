# 1662. Check If Two String Arrays are Equivalent
# https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

class Solution(object):
    def arrayStringsAreEqual(self, word1, word2):
        """
        :type word1: List[str]
        :type word2: List[str]
        :rtype: bool
        """
        # return "".join(word1) == "".join(word2)
        # using yield
        # generators are iterators that do not store all values in memory
        # generate the value on fly

        '''
        Yield Returns a Value: When the yield statement is executed, it 
        produces a value and pauses the function's execution, saving its 
        state for later. The function can then be resumed right after the 
        yield statement.
        '''

        def generate(wordlist):
            for word in wordlist:
                for char in word:
                    yield char
            yield None

        for c1, c2 in zip(generate(word1), generate(word2)):
            if c1 != c2:
                return False
        return True

        

        