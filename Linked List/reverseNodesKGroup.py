# 25. Reverse Nodes In K Group
# https://leetcode.com/problems/reverse-nodes-in-k-group/description/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        lefty = head
        dummy = support = ListNode(0)

        length = 0
        while head:
            head = head.next
            length += 1
        
        for i in range(length // k):
            remember = lefty
            for _ in range(k):
                nexty = lefty.next
                lefty.next = support.next
                support.next = lefty
                lefty = nexty
            support = remember  # this does not effect dummy
        support.next = lefty

        return dummy.next