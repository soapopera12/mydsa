// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:

    bool solve(int index,int target, vector<int>&arr, int N, int sum,vector<vector<int>>&dp) {

        if(index>=N) return false ;
        if(sum>target) return false;
        if(sum==target) return true;
        if(dp[index][sum]!=-1) return dp[index][sum];
        bool take=solve(index+1,target,arr,N,sum+arr[index],dp);
        bool nottake=solve(index+1,target,arr,N,sum,dp);
        return dp[index][sum]= (take || nottake);

    }

    bool canPartition(vector<int>& nums) {

        int sum=0;
        int N=nums.size();
        for(int i=0;i<N;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>>dp(N+1,vector<int>(target+1,-1));
        return solve(0,target,nums,N,0,dp);

    }
};

    // works but has high space complexity -> 3D dp
    // bool solve(int current, vector<int> &nums, int left, int right, vector<int> & dp) {

    //     // base case
    //     if(current >= nums.size()) {
    //         return (left == right);
    //     }

    //     // if(dp[current] != -1) {
    //     //     if(dp[current]){
    //     //         return true;
    //     //     }
    //     //     return false;
    //     // }

    //     // left or right situation kinda like knapsack
    //     bool lefty = solve(current+1,nums,left+nums[current],right);
    //     bool righty = solve(current+1,nums,left,right+nums[current]);

    //     dp[current] = (left || right)? 1 : 0;
    //     return (lefty || righty);           // i made a mistake here  wrote left || right -> avoid keeping similar variable names
    // }