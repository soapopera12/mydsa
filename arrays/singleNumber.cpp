// 136. Single Number
// https://leetcode.com/problems/single-number/description/?envType=list&envId=xleo1moc

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // bit manipulation
        // bitwise XOR 

        // only thing you need to remeber is 
        // A ^ A = 0(even times)
        // A ^ A ^ A = A(odd times)
        // so if we XOR all elements in the array
        // the unique element will only be left rest are cancelled

        int ans = 0;
        for(auto x : nums){
            ans ^= x;
        }

        return ans;
    }
};