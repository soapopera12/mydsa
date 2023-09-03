// Longest Common Subsequence
// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

class Solution
{
    public:
    //recursive func with memoization
    int solve(int n,int m, string s1, string s2, vector <vector<int>> &dp){
        
        if( n == 0 || m == 0)
            return 0;
        
        if( dp[n][m] != -1)
            return dp[n][m];
            
        if(s1[n-1] == s2[m-1])
            return dp[n][m] = 1 + solve(n-1,m-1,s1,s2,dp);
        
        return dp[n][m] = max(solve(n,m-1,s1,s2,dp),solve(n-1,m,s1,s2,dp));
        
    }
    
    //tabluation method
    int solveTab(int n,int m, string s1, string s2){
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i == 0 || j== 0)
                    dp[i][j] = 0;
                else if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
    
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        //int ans = solve(n,m,s1,s2);
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, -1));
        return solveTab(n,m,s1,s2);
    }
};