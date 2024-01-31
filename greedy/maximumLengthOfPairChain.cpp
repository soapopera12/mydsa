// 646. Maximum Length of Pair Chain
// https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        // sort karo
        // 3 parameter sorting
        // start - end - lambda function on how to sort
        sort(pairs.begin(),pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];     // sorting by second number .. because we want to apply greedy 
        });

        int current = INT_MIN;
        int ans = 0;

        for(const auto &pair:pairs) {
            
            if(current < pair[0]) {
                current = pair[1];
                ans++;
            }

        }

        return ans;
    }
};