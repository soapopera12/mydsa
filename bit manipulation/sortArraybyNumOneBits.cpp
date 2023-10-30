// 1356. Sort Integers by The Number of 1 Bits
// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/

class Solution {
public:

    int setBitsCount(int n) {
        int count = 0;
        while(n > 0){
            n = n & (n - 1);
            count++;
        }
        return count;
    }


    vector<int> sortByBits(vector<int>& arr) {
        
        vector<pair<int,int>> mapBin;

        for(auto x : arr){
            int count = setBitsCount(x);
            mapBin.push_back({count,x});
        }

        sort(mapBin.begin(),mapBin.end());
        vector<int> ans;

        for(auto x : mapBin){
            // if you mantain a pair you dobnt have to worry about sorting and
            // ordering of two arrays
            ans.push_back(x.second);
        }

        return ans;
    }
};