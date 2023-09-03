// 0 - 1 Knapsack Problem
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution
{
    public:
    int solve(int W, int wt[], int val[], int n,vector<vector<int>>& dp){
        if(n == 0 || W == 0){
            return 0;
        } 
        
        if(dp[W][n] != -1){
            return dp[W][n];
        }
        
        int maxProfit = INT_MIN;
        
        if(wt[n-1] <= W){       //seriously bruh you forgot to put an equal to sign here 
                                //and wasted 15 mins
            //include
            if(dp[W-wt[n-1]][n-1] == -1){
                int nextIncItem = solve(W-wt[n-1],wt,val,n-1,dp);
                dp[W-wt[n-1]][n-1] = nextIncItem;
            }
            int includeItem = val[n-1] + dp[W-wt[n-1]][n-1];
            
            //exclude
            if(dp[W][n-1] == -1){
                int nextIncItem = solve(W,wt,val,n-1,dp);
                dp[W][n-1] = nextIncItem;
            }
            int excludeItem = dp[W][n-1];
            
            maxProfit = max(includeItem,excludeItem);
        }
        else{
            if(dp[W][n-1] == -1){
                int nextIncItem = solve(W,wt,val,n-1,dp);
                dp[W][n-1] = nextIncItem;
            }
            maxProfit = max(maxProfit,dp[W][n-1]);
        }
        
        return dp[W][n] = maxProfit;
    }
    
    int solveTab(int W, int wt[], int val[], int n,vector<vector<int>>& dp){
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][W];
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int>(W+1,0));
       return solveTab(W,wt,val,n,dp);
    }
};