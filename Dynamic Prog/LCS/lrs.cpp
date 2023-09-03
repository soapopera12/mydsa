// Longest Repeating Subsequence
// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

class Solution {
	public:
	    // recursion and memoization
	    int solve(string str1,string str2,int a,int b){
	        if(a-1 == 0 || b-1 == 0){
	            return 0;
	        }
	        else if(str1[a-1] == str2[b-1] && a!=b){
	            return 1 + solve(str1,str2,a-1,b-1);
	        }
	        else{
	            return max(solve(str1,str2,a,b-1),solve(str1,str2,a-1,b));
	        }
	    }
	    
	    //tabulation
	    int solveTab(string str1,string str2,int a,int b){
	        vector<vector<int> > dp(a+1,vector<int>(b+1,0));
	        
	        for(int i=0;i<=a;i++){
	            for(int j=0;j<=b;j++){
	                if(i==0 || j==0){
	                    dp[i][j] = 0;
	                }
	                else if(str1[i-1] == str2[j-1] && i!=j){
	                    dp[i][j] = 1 + dp[i-1][j-1];
	                }
	                else{
	                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
	                }
	            }
	        }
	        
	        return dp[a][b];
	    }
	
	
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    //return solve(str,str,str.length(),str.length());
		    return solveTab(str,str,str.length(),str.length());
		}

};