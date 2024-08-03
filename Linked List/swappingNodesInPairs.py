# 24. Swapping Nodes in Pairs
# https://leetcode.com/problems/swap-nodes-in-pairs

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        dummy = prev = ListNode(0)
        prev.next = head

        while prev.next and prev.next.next:
            a = prev.next        # exchange1
            b = prev.next.next   # exchange2
            c = prev.next.next.next  # rewiring
            prev.next = b            # prev points to 2nd element very important
            prev.next.next = a       # 2nd now points to 1st element
            prev.next.next.next = c  # 1st now points to next of 2nd element previously
            prev = prev.next.next    # skipping 2 elements

        return dummy.next 


