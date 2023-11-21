// 1814. Count Nice Pairs in an Array
// https://leetcode.com/problems/count-nice-pairs-in-an-array/
class Solution {
public:

    const int MOD = 1000000007;

    int rev(int num) {

        int ans = 0;
        while(num) {
            ans = ans * 10 + num%10;
            num = num/10;
        }
        return ans;
    }

    int countNicePairs(std::vector<int>& nums) {

        int n = nums.size();

        // doing nums[i] - rev(nums[i])
        for(int i=0;i<n;i++) {
            nums[i] = nums[i] - rev(nums[i]);
        }

        // sorting
        sort(nums.begin(), nums.end());

        // counting consecutive similar elements
        long ans = 0;
        for(int i=0;i<n;i++) {
            long consecutive = 1;
            while(i<n-1 && nums[i] == nums[i+1]) {  // ensure boundary and situation
                consecutive++;
                i++;
            }
            ans = (ans % MOD + (consecutive * (consecutive - 1)) / 2) % MOD;

        }

        return static_cast<int>(ans%MOD);

    }
};