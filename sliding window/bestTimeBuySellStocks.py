# 121. Best Time to Buy and Sell Stock
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # kadane solution
        # It says don't shift left pointer until your profit is higher
        # but once your profit is 0 or negative shift left pointer to current place and continue

        # initally pointer
        left = 0
        right = 1

        # max profity profity $$$$
        maxi_profity = 0

        while right < len(prices):
            current_profity = prices[right] - prices[left]
            maxi_profity = max(maxi_profity, current_profity)
            if prices[right] <= prices[left]:
                # we are dipping from where we started
                left = right
            right += 1
        
        return maxi_profity



