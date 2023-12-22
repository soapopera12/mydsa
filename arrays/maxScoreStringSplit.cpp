// 1422. Maximum Score After Splitting a String 
// https://leetcode.com/problems/maximum-score-after-splitting-a-string/

class Solution {
public:
    
    int maxSplitScore(const std::string& s) {

        int zeroCount = 0;
        int oneCount = 0;
        int maxi = 0;

        for(int i=0;i<s.size();i++) {
            if(s[i] == '1') {
                oneCount++;
            }
        }

        for(int i=0;i<s.size()-1;i++) {
            if(s[i] == '1') {
                oneCount--;
            }
            else {
                zeroCount++;
            }

            maxi = max(maxi,zeroCount+oneCount);
        }

        return maxi;      

    }

    int maxScore(const std::string& s) {
        
        return maxSplitScore(s);

    }
};