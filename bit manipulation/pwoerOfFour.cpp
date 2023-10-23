// 342. Power of Four
// https://leetcode.com/problems/power-of-four/

class Solution {
public:
    // bit manipulation
    // bool isPowerOfFour(int n) {
        
    //     return n > 0 && (n&(n-1)) == 0 && (n&0x55555555);
    // }

    
    // recursive solution
    bool isPowerOfFour(int n) {
        
        if(n == 0){
            return false;
        }
        if(n == 1){
            return true;
        }
        return n%4 == 0 && isPowerOfFour(n/4);
    }

};