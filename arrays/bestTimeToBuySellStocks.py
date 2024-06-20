# 122. Best Time to Buy and Sell Stock II
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution(object):

    # def dynamix(n, lastBuy, prices):
    #     # check if end of array
    #     if n == len(prices) - 1:
    #         return prices[n] - lastBuy    # return the price at the last day

    #     # option 1 -> hold
    #     int hold = dynamix(n+1, lastBuy, prices)

    #     int sell = prices[n] - lastBuy + dynamix(n+1, prices[n], prices)

    #     return max(hold, sell)

    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # simple O(n) solution
        # simple greedy approach
        if not prices or len(prices) is 1:
            return 0
        
        profit = 0
        
        for i in range(1, len(prices)):
            if prices[i] > prices[i-1]:
                profit += prices[i] - prices[i-1]

        return profit
            


        