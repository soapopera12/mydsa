// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:

    int recursiveMonkey(int curr,int prev, vector<int>& nums,vector<vector<int>>& dp){
        
        if(curr >= nums.size()){
            return 0;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];    // to stablalize the -1 to linear
        }

        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            take = 1 + recursiveMonkey(curr+1,curr,nums,dp); 
        }

        // not take condition
        int not_take = 0 + recursiveMonkey(curr+1,prev,nums,dp);
        
        return dp[curr][prev+1] = max(take,not_take);

    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1)); // one more column for -1
        return recursiveMonkey(0,-1,nums,dp);
    }
};