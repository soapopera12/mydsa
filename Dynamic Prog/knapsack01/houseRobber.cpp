// 198. House Robber
// https://leetcode.com/problems/house-robber/description

class Solution {
public:

    int solve(vector<int> & nums, int n,vector<int> &dp) {

        // base case
        if(n == nums.size() - 1) {
            return nums[n];
        }

        // base case 2
        if(n >= nums.size()) {
            return 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        // take | not take
        int take = nums[n] + solve(nums, n + 2,dp);
        int not_take = solve(nums,n+1,dp);

        return dp[n] = max(take,not_take);

    }

    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size()+1,-1);
        return solve(nums,0,dp);

    }
};