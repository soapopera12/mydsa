// 518. Coin Change II
// https://leetcode.com/problems/coin-change-ii

class Solution {
public:

    int solve(int current, int amount, vector<int> &coins, vector<vector<int>> &dp) {

        // base case 1
        if(amount == 0) {
            return 1;       // iske aage to nahi ja sakte hai
        }

        // base case 2
        if(current >= coins.size()) {
            return 0;       // khatam ho gaya amount is checked above no need to do anything here 
        }

        if(dp[current][amount] != -1) {
            return dp[current][amount];
        }

        //  situations is 2 
        // 4th situation does not make any sense -> no take no inc 
        // 3rd sitatuion -> if take no inc is done it will also cover take inc -> from previous function - gives stack overflow

        // take no inc
        int takeNoInc = 0;
        if(coins[current] <= amount) {
            takeNoInc = solve(current,amount-coins[current],coins,dp);
        }

        // no take inc
        int noTakeInc = solve(current+1,amount,coins,dp);

        return dp[current][amount] = (takeNoInc + noTakeInc);

    }

    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);

    }
};