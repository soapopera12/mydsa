# 1208. Get Equal Substrings Within Budget
# https://leetcode.com/problems/get-equal-substrings-within-budget

class Solution(object):
    def equalSubstring(self, s, t, maxCost):
        """WWW
        :type s: str
        :type t: str
        :type maxCost: int
        :rtype: int
        """
        # simply find the cost of changing every char of s to t
        # find the smallest substring
        # then for each change dec maxCost 

        # optimal way?
        # using sliding window
        start = 0
        current_cost = 0
        max_substring = 0
        n = len(s)

        for end in range(n):
            
            # 1. first calculate the current_cost
            current_cost += abs(ord(s[end]) - ord(t[end]))
            
            # 3. if maxCost overflows
            while maxCost < current_cost:
                # increase the start pointer till you don't overflow anymore
                current_cost -= abs(ord(s[start]) - ord(t[start]))
                start += 1

            # 2. check the max_substring
            max_substring = max(max_substring, end - start + 1)

        return max_substring