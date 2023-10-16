// 72. Edit Distance
// https://leetcode.com/problems/edit-distance/

class Solution {
public:
    
    int solve(int i, int j,string & word1, string & word2,vector<vector<int>> & dp){

        if(i == 0){
            return dp[i][j] = j;       // delete operations
        }

        if(j == 0){
            return dp[i][j] = i;       // insert operations
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(word1[i-1] == word2[j-1]){
            return dp[i][j] = solve(i-1,j-1,word1,word2,dp);
        }
        else{
            // 3 conditions
            int insertChar = solve(i,j-1,word1,word2,dp);
            int deleteChar = solve(i-1,j,word1,word2,dp);
            int replaceChar = solve(i-1,j-1,word1,word2,dp);

            return dp[i][j] = 1 + min({insertChar,deleteChar,replaceChar});    // nice way to compare 3 int values
        }     

        
    }

    int minDistance(string word1, string word2) {
        int i = word1.size(), j = word2.size();
        vector<vector<int>> dp(i+1,vector<int>(j+1,-1));
        return solve(i,j,word1,word2,dp);
    }
};