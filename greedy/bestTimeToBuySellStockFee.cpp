// 714. Best Time to Buy and Sell Stock with Transaction Fee
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
    
        // greedy 
        // greedy - buy at a particular price
        // calculate the amount costed to buy the stock
        // and in order to have the best pick use max function to 
        // buy = max(buy, sell - current);
        // for selling consider the amount of 
        // sell = max(sell,buy - sell - fee);

        int buy  = INT_MIN;
        int sell = 0;
    
        for(auto price: prices) {

            buy = max(buy,sell - price);
            sell =max(sell, buy + price - fee);

        }

        return sell;

                        
        
    }
};