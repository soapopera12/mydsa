// 779. K-th Symbol in Grammar
// https://leetcode.com/problems/k-th-symbol-in-grammar/description/

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1)
            return 0;
        int smallAns = kthGrammar(n-1, (k+1)/2);
        if(smallAns == 0) {
            return (k&1) ? 0 : 1;
        }
        return (k&1) ? 1 : 0;
    }
};