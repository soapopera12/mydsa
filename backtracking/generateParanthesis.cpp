// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/description

class Solution {
public:

    vector<string> ans;

    void solve(int open, int close,int n,string str) {
        // recursive code
        // base case
        if(str.length() == n*2) {
            // string cannot be any longer
            ans.push_back(str);
            return;
        }

        if(open < n) {
            // not allowing open to go above n
            // one option is to open the bracket
            solve(open+1,close,n,str+"(");
        }

        if(close < open) {
            // not allowing close to be higher than open
            // another is to close the bracket
            solve(open, close+1,n,str+")");
        }

    }

    vector<string> generateParenthesis(int n) {

        string str = "";
        solve(0,0,n,str);
        return ans;

    }
};