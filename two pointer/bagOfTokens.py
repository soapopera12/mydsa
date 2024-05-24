# 948. Bag of Tokens
# https://leetcode.com/problems/bag-of-tokens

class Solution(object):
    def bagOfTokensScore(self, tokens, power):
        """
        :type tokens: List[int]
        :type power: int
        :rtype: int
        """
        tokens.sort()  # tokens ko sort karo taki we can keep adding to score by +1 till we reach
        n = len(tokens)
        score = 0
        max_score = 0
        left = 0
        right = n - 1
        while left <= right:
            if power >= tokens[left]:
                power -= tokens[left]
                score += 1
                left += 1
                max_score = max(max_score, score)
            elif score > 0:
                power += tokens[right]
                score -= 1
                right -= 1
            else:
                break # nothing to do 
        return max_score