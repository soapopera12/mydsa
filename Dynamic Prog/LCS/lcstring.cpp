// Longest Common Substring
// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
    public:
    int ans = 0;
    int solve(string S1, string S2, int n,int m,vector<vector<int>> & dp){
        
        if(n < 0 || m < 0){
            return 0;
        }
        
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        
        int commSubstrLen = 0;
        
        if(S1[n] == S2[m]){
            commSubstrLen = 1 + solve(S1,S2,n-1,m-1,dp);
            ans = max(ans,commSubstrLen);
        }
        
        solve(S1,S2,n,m-1,dp);
        solve(S1,S2,n-1,m,dp);
        
        
        dp[n][m] = commSubstrLen;

        return commSubstrLen;
    }
    
    int solveTab(string S1,string S2, int n, int m){
        // code here
        // your code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
            }
        }
        
        int ans=0;
          for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               ans=max(ans,dp[i][j]);
            }
        }
        
        return ans;
    }
    
    // int maxi=0;
    // int help(string& s1,string& s2,int i,int j)
    // {
    //     //base case
    //     if(i<0 or j<0)
    //         return 0;
        
    //     int take=0;
    //     if(s1[i]==s2[j])
    //     {
    //         take = 1 + help(s1,s2,i-1,j-1);
    //         maxi = max(take,maxi);  //we only need thw value of maxi rest of everything is not required
    //     }
        
    //     help(s1,s2,i-1,j);  //what happens here 
    //     help(s1,s2,i,j-1);  
        
    //     return take;            //not required
    // }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        
        // int a=help(S1,S2,n-1,m-1);
        // return maxi;
        
        //vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        //int a = solve(S1,S2,n-1,m-1,dp);
        return solveTab(S1,S2,n,m);
    }
};



