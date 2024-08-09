# 206. Reverse Linked List
# https://leetcode.com/problems/reverse-linked-list/description/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head

        prev = None
        nexty = None

        while head:
            nexty = head.next
            head.next = prev
            prev = head
            head = nexty
        
        return prev
        