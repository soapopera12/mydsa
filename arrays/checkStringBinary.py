# 1461. Check If a String Contains All Binary Codes of Size K
# https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k

class Solution(object):
    def hasAllCodes(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        # 00110110 -> 00 11 01 10 -> 0 01 10 11 0 -> all pairs covered
        # Generate all binary codes of length k
        # store them in a hashtable or a set
        # create two loops to generate all possible available string
        # calculate n = 2^k
        # if n == size of set|hash -> all possible numbers are available
        codes = set()
        
        for i in range(len(s) - k + 1):
            codes.add(s[i:i+k])
        
        return len(codes) == 2 ** k