// 1269. Number of Ways to Stay in the Same Place After Some Steps
// https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/

// memory limit exceeded
// class Solution {
// public:
//     int MODULO = 1000000007;

//     long long solve(int curr,int steps,int arrLen,vector<vector<int>> &dp){
//         if(curr < 0 || curr >= arrLen){
//             return -1;
//         }

//         if(steps < 0){
//             return 0;
//         }

//         if(steps == 0 && curr == 0){
//             return 1;
//         }

//         if(dp[curr][steps] != -1){
//             return dp[curr][steps];
//         }

//         long long ans = 0;

//         // right 
//         int right = solve(curr+1,steps-1,arrLen,dp);
//         if(right != -1){
//             ans += right%MODULO;
//         }

//         // left
//         int left = solve(curr-1,steps-1,arrLen,dp);
//         if(left != -1){
//             ans += left%MODULO;
//         }

//         // stay
//         int stay = solve(curr,steps-1,arrLen,dp);
//         ans += stay%MODULO;

//         return dp[curr][steps] = ans%MODULO;

//     }

//     int numWays(int steps, int arrLen) {

//         vector<vector<int>> dp(arrLen+1,vector<int>(steps+1,-1));
//         return solve(0,steps,arrLen,dp);
//     }
// };

// so how does this work lol same !! 

class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1000000007;
        std::vector<std::vector<long long>> memo(steps + 1, std::vector<long long>(std::min(arrLen, steps) + 1, -1));
        
        return dp(steps, 0, arrLen, MOD, memo);
    }
    
    long long dp(int step, int index, int arrLen, const int MOD, std::vector<std::vector<long long>>& memo) {
        if (step == 0) {
            return (index == 0) ? 1 : 0;
        }
        if (step < 0 || index < 0 || index >= arrLen) {
            return 0;
        }
        if (memo[step][index] != -1) {
            return memo[step][index];
        }
        
        long long ways = dp(step - 1, index, arrLen, MOD, memo) % MOD;
        ways += dp(step - 1, index - 1, arrLen, MOD, memo) % MOD;
        ways += dp(step - 1, index + 1, arrLen, MOD, memo) % MOD;
        
        memo[step][index] = ways % MOD;
        return ways % MOD;
    }
};


