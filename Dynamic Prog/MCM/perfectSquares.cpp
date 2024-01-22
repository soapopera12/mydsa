// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares

// working simple memo soltion
#include <cmath>

class Solution {
public:

    int solve(int n, vector<int> &dp) {

        if(n == 0) {
            return dp[0] = 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        int ans = n;

        for(int i=1;i * i <= n;i++) {
            ans = min(ans, solve(n-i*i,dp) + 1);
        }
        
        return dp[n] = ans;
    }



    int numSquares(int n) {

        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};




// my solution fails a few test case 
#include <cmath>

class Solution {
public:

    bool squared(int num) {
        int squareRoot = sqrt(num);
        return squareRoot * squareRoot == num;
    }

    int solve(int n, vector<int> &dp) {

        if(dp[n] != -1) {
            return dp[n];
        }

        // basecase 1
        if(n == 0) {
            return 0;
        }

        // base case 2
        if(squared(n)) {
            return 1;
        }

        int mini = INT_MAX;

        for(int i=1;i<n;i++) {
            if(squared(n-i)) {
                mini = min(mini, 1+solve(i,dp));
            }
        }

        return dp[n] = mini;

    }

    int numSquares(int n) {

        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};