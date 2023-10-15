// Matrix Chain Multiplication
// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// User function Template for C++

class Solution{
public:
    //top-down approach
    int solve(int i,int j,int arr[], vector <vector<int>> &dp){
    
        if(i == j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int minMulti = INT_MAX;
        
        for(int k=i;k<j;k++){
            
            int steps = arr[i-1] * arr[k] * arr[j] 
                + solve(i,k,arr,dp) + solve(k+1,j,arr,dp);
                
            if(steps < minMulti)
                minMulti = steps;
        }
        
        return dp[i][j] = minMulti ;
            
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector <vector<int>> dp(N,vector<int> (N,-1));
        return solve(1,N-1,arr,dp);
    }
};