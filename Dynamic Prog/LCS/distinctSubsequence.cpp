// 115. Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences/description/

class Solution {
public:

    int solve(int i, int j, string &s,string &t, vector<vector<int>> &dp){
        if(i == 0 && j == 0){
            return 1;
        }

        if(i == 0){
            return 0;
        }

        if(j == 0){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i-1] == t[j-1]){
            return dp[i][j] = solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);
        }

        return dp[i][j] = solve(i-1,j,s,t,dp);

    }

    int numDistinct(string s, string t) {
        // lcs method
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        return solve(s.size(),t.size(),s,t,dp);
    }
};