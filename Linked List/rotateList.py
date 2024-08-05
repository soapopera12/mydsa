# 61. Rotate List 
# https://leetcode.com/problems/rotate-list

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return None

        length = 1
        start = head

        while start.next:
            length += 1
            start = start.next
        
        # find the overflow for k
        start.next = head

        k = k % length

        start = head

        for i in range(length - k - 1): # stoppin one element before the break
            start = start.next
        
        ans = start.next
        start.next = None

        return ans

