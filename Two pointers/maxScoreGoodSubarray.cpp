// 1793. Maximum Score of a Good Subarray
// https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/


class Solution {
public:
    // find good sub array
    // find maximum possible score of good sub array
    int maximumScore(vector<int>& nums, int k) {
        
        // check
        int left = k;
        int right = k;
        int min_val = nums[k];
        int max_score = min_val;

        while(left > 0 || right < nums.size() - 1){
            if(left == 0 || (right < nums.size() - 1 && nums[right + 1] > nums[left - 1])) {
                right++;
            }
            else{
                left--;
            }
            min_val = min(min_val,min(nums[left],nums[right]));
            max_score = max(max_score,min_val * (right-left + 1));
        }

        return max_score;

    }
};