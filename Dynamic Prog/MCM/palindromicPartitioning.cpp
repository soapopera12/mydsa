// Palindromic Partitioning
// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

// User function Template for C++

class Solution{
public:
    
    bool ispalindrome(int i ,int j, string &str){
        while(i < j){
            if(str[i] != str[j]) return false;
            i++, j--;
        }
        return true;
    }

    int palindromicPartition(string str)
    {
        int n =str.size();
        vector<int> dp(n+1, 0);
    
        for(int i=n-1; i>=0 ; i--){
            int mini = INT_MAX;
            for(int j = i; j<n; j++){
            if(ispalindrome(i,j,str)){
                int ways = 1 + dp[j+1];
                mini = min(mini , ways);
            }
        }
        dp[i] = mini;
        }
        return dp[0] -1;
    }
};