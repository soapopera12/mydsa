// 455. Assign Cookies
// https://leetcode.com/problems/assign-cookies/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        // sort karo dono array aur assign karte jao

        // assuming arrays are sorted
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int child = 0;
        int count = 0;

        for(int i=0;i<s.size();i++) {
            if(g[child] <= s[i]) {
                count++;
                child++;
            }
            if(child >= g.size()) {
                break;
            }
        }

        return count;

    }
};