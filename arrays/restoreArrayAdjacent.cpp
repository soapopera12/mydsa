// 1743. Restore the Array From Adjacent Pairs
// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    
        unordered_map <int,vector<int>> pair;

        for(auto k:adjacentPairs) {
            pair[k[0]].push_back(k[1]);     // best way to resolve this
            pair[k[1]].push_back(k[0]);            
                       
        }

        // pair map is ready
        // find common adjacent elements
        // only one adjacent element is either left side or right side

        vector<int> result;
        int start = -1000000;

        //find start

        for(auto vec:pair) {
            if(vec.second.size() == 1) {
                start = vec.first;
                break;
            }
        }

        int left = -1000000;

        result.push_back(start);

        for(int i=1;i<adjacentPairs.size()+1;++i) {
            vector<int>& val = pair[start];
            int newval = (val[0] == left) ? val[1] : val[0];
            result.push_back(newval);
            left = start;
            start = newval;
        }

        return result;

    }
}; 