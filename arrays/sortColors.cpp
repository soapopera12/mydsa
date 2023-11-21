// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/description/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort 3 number array
        // red white blue
        int l = 0;
        int mid = 0;
        int r = nums.size()-1;      // 3 way partitioning
        while(mid <= r){
            if(nums[mid] == 0) {
                swap(nums[mid],nums[l]);
                mid++;
                l++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid],nums[r]);
                r--;
            }
        }       

    }
};