# 907. Sum of Subarray Minimums
# https://leetcode.com/problems/sum-of-subarray-minimums/description/

class Solution(object):
    def sumSubarrayMins(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        arr = [0] + arr
        result = [0] * len(arr)
        stack = [0]
        for i in range(len(arr)):
            while arr[stack[-1]] > arr[i]:
                stack.pop()
            j = stack[-1]
            result[i] = result[j] + (i-j) * arr[i]
            stack.append(i)
        return sum(result) % (10 ** 9 + 7)

        # https://leetcode.com/problems/sum-of-subarray-minimums/solutions/257811/python-o-n-slightly-easier-to-grasp-solution-explained

        