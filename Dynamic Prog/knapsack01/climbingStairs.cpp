
// 746. Min Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/description/

class Solution {
public:
    int MAXI = 100000;

    int solve(int curr,vector<int>& cost,vector<int> &dp) {
        // take not take situation
        if(curr == cost.size()){
            return 0;
        }
        
        if(curr >= cost.size()){
            return MAXI;
        }

        if(dp[curr] != -1){
            return dp[curr];
        }

        int takeOneStep = cost[curr] + solve(curr+1,cost,dp);
        int takeTwoStep =  cost[curr] + solve(curr+2,cost,dp);

        return dp[curr] = min(takeOneStep,takeTwoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // take not take situation
        vector<int> dp(cost.size(),-1);
        return min(solve(1,cost,dp),solve(0,cost,dp));
    }
};