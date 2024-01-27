// 376. Wiggle Subsequence
// https://leetcode.com/problems/wiggle-subsequence

class Solution {
public:

    int solve(int index, int sign, vector<int> &nums, vector<vector<int>> &dp) {

        if(dp[sign][index] != -1) {
            return dp[sign][index];
        }
        int ans = 1;

        for(int i=index+1;i<nums.size();i++) {

            if(sign == 1) {      // outer is required sign sign inner is computed sign
                // finding the -ve signs
                if(nums[i] - nums[index] > 0) {
                    ans = max(ans,1 + solve(i,0,nums,dp));
                }
            }
            else {
                // finding the +vs signs
                if(nums[i] - nums[index] < 0) {
                    ans = max(ans,1 + solve(i,1,nums,dp));
                }
            }

        }

        return dp[sign][index] = ans;

    }

    int wiggleMaxLength(vector<int>& nums) {
        // lcs + wiggle
        int n = nums.size();

        vector<vector<int>> dp(2,vector<int>(nums.size()+1,-1));
        
        // calculatinf for both +ve and -ve start sign
        return max(solve(0,0,nums,dp),solve(0,1,nums,dp));

    }
};





    // knapsack 01 
    // int solve(int index, int lastIndex, char sign, vector<int> &nums) {

    //     // base case
    //     if(index >= nums.size()-1) {        // -1 for end case
    //         return 0;
    //     }

    //     // not take condition
    //     int not_take = 0 + solve(index+1,lastIndex,sign,nums);


    //     // take condition
    //     int take = 0;

    //     // positive
    //     if(lastIndex == -1 || nums[index] - nums[lastIndex-1] < 0) {    
    //         if(sign == '+' || sign == '=') {
    //             lastIndex = index;
    //             take =  1 + solve(index+1,lastIndex,'-',nums);
    //         }
    //     }

    //     //negative
    //     if(lastIndex == -1 || nums[index] - nums[lastIndex-1] >= 0) {
    //         if(sign == '-' || sign == '=') {
    //             lastIndex = index;
    //             take = 1 + solve(index+1,lastIndex,'+',nums);
    //         }
    //     }

    //     return max(take,not_take);       

    // }

    // int wiggleMaxLength(vector<int>& nums) {
    //     // lcs + wiggle
    //     if(nums.size()<2){
    //         return nums.size();
    //     }
        
    //     return solve(0,-1,'=',nums);
    // }