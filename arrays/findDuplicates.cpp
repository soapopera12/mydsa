// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/?envType=list&envId=xleo1moc

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // return an array of all int that appear twice
        // once or twice
        //other ways to solve this is using map, set, array
        // find duplicates in constant extra space
        
        vector<int> duplicates;
        
        for(int i=0;i<nums.size();i++){
            int indexOfElem = abs(nums[i]) - 1;     // this abs is used to make +ve element
            nums[indexOfElem] = -nums[indexOfElem];

            if(nums[indexOfElem] > 0){
                duplicates.push_back(indexOfElem+1);
            } 
        }

        return duplicates;
    }
};