# 167. Two Sum II - Input Array Is Sorted
# https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        i = 0
        j = len(numbers) - 1
        ans = []
        while i<j:
            if numbers[i] + numbers[j] == target:
                return (i + 1, j + 1)
            if numbers[i] + numbers[j] > target:
                j -= 1
            else:
                i += 1 

            # understanding it this way
            # if left + right > target
            #       left > target - right : target is still greater than left so decrease right
            #       left < target - right : target is still less than left so increase left