// 2433. Find The Original Array of Prefix Xor
// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // bitwise x-or method

        int prev = pref[0];     // first element

        for(int i=1;i<pref.size();i++){ // remember to start from 1
            // (next)prev = (current)prev ^ pref[i]
            pref[i] ^= prev;
            prev ^= pref[i];
        }

        return pref;
    }
};