# 881. Boats to Save People
# https://leetcode.com/problems/boats-to-save-people

class Solution(object):
    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        # sort 
        people.sort()
        n = len(people)
        r = n - 1
        boats = 0
        l = 0

        while l <= r:
            if people[l] + people[r] <= limit:
                l += 1
                r -= 1
            else:
                r -= 1
            boats += 1
        return boats

        