
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


// leetcode solution much better

class Solution {
public:
    int solve(int n, vector<int> &dp){

        if(n == 0 || n == 1){                 // base case is tricky
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        // 1 step
        int oneStep = solve(n-1,dp);

        //two Step
        int twoStep = solve(n-2,dp);

        return dp[n] = (oneStep + twoStep);

    }

    int climbStairs(int n) {

        if(n <= 2){
            return n;
        }

        vector<int> dp(n+1,-1);

        return solve(n-1,dp) + solve(n-2,dp); 
    }
};