// 2706. Buy Two Chocolates
// https://leetcode.com/problems/buy-two-chocolates/description/

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {

        int first = INT_MAX;
        int second = INT_MAX;

        for(int p:prices) {
            if(p<first) {
                second = first;
                first = p;
            }
            else {
                second = min(second,p);
            }
        }

        int remainMoney = money - (first + second);

        return remainMoney >=0 ? remainMoney : money;
    }
};