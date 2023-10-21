// 1425. Constrained Subsequence Sum
// https://leetcode.com/problems/constrained-subsequence-sum/description/?envType=daily-question&envId=2023-10-21

class Solution {
public:

    // knapsack dp 0/1
    // this gives error for last case 3
    int solve(int prev, int curr,vector<int> &nums,int k){
        
        if(curr == nums.size()){
            return 0;
        }

        // check if current can be taken with prev

        // not take condition
        int not_take = solve(prev,curr+1,nums,k);

        int take;
        
        if(prev - curr <= k || prev == -1){
            // take condition
            take = nums[curr] + solve(curr,curr+1,nums,k);
        }

        if(max(take,not_take) == 0){
            return -1;
        }
        return max(take,not_take);

    }


    int constrainedSubsetSum(vector<int>& nums, int k) {

        //return solve(-1,0,nums,k);
        // sliding window method
        std::deque<int> dq;
        for(int i=0;i<nums.size();i++){
            nums[i] += !dq.empty() ? nums[dq.front()] : 0;  // if empty dq push from front

            while(!dq.empty() && (i - dq.front() >= k || nums[i] >= nums[dq.back()])) {
                if(nums[i] >= nums[dq.back()]){
                    dq.pop_back();         // why 
                } 
                else{
                    dq.pop_front();
                }
            }

            if(nums[i] > 0){
                dq.push_back(i);
            }
        }

        return *std::max_element(nums.begin(), nums.end());     // huh

    }
};