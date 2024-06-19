# 525. Contiguous Array
# https://leetcode.com/problems/contiguous-array

class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # longest contiguous subarray of equal number of 0 and 1
        # 0 1 0
        
        # initialize variable count by 0 and result by 0
        # iterate over the array 
        # if current number is 0 we decrement count by 1
        # if current number is 1 we increment count by 1
        # if count is equal to 0 we can update result by i+1
        # update count to hash, if it was already in hash we will compare hash with max_len and if it is greater than max_len then we update max_len to the value of hash
        count = 0
        result = 0
        dict_seen = {0:-1}

        for i in range(len(nums)): # somw what like prefix sum
            n = nums[i]
            if n == 0:
                count -= 1
            if n == 1:
                count += 1
            
            if count in dict_seen:
                result = max(result, i - dict_seen[count])   # if current count is higher than best result till now we update result - middlle cases
            else:
                dict_seen[count] = i   # marking the current location 
            
        return result




