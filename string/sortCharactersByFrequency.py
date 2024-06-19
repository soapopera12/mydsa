# 451. Sort Characters By Frequency
# https://leetcode.com/problems/sort-characters-by-frequency/

class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        # hash the letters abd then paste it in a string
        ans = []

        for letter in set(s):
            count = s.count(letter)   # count merhod for string 
            ans.append(letter*count) # ans is ready
        
        ans = sorted(ans, key=len, reverse = True) # sorting in reverse order
                        # sort the array based on key=len based on length of each element

        return "".join(ans) 


        # alternative method is to use a Counter