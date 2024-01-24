// 343. Integer Break
// https://leetcode.com/problems/integer-break

class Solution {
public:

    int solve(int n, vector<int> &dp) {
        
        // base case 
        if(n <= 2) {
            return 1;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        int maxi = 0;
        // checking for all the possibilities
        for(int i=1;i<n;++i) {          // remember the signs properly
            // current * remaining or current * solve(further) .... 
            maxi = max(maxi, max(i * (n-i),i * solve(n-i,dp)));
        }   

        return dp[n] = maxi;
    }

    int integerBreak(int n) {

        vector<int> dp(n+1,-1);
        return solve(n,dp);

    }
};