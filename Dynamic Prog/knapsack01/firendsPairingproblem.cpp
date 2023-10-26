// Friends Pairing Problem
// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/0

class Solution
{
public:
    int MOD = 1000000007;
    long long int calculate(int n, long long int dp[]){
        if(n == 1)
            return 1;
            
        if(n == 2)
            return 2;
        
        if(dp[n] != -1)
            return dp[n];
        
        long long int singled = calculate(n-1,dp)%MOD;

        long long int paired = (( (n-1)%MOD) * calculate(n-2,dp)%MOD) % MOD;
        
        return dp[n] = singled + paired;   
    }
    int countFriendsPairings(int n) 
    { 
        // base case
        long long int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return calculate(n,dp) % MOD;
    }
};    