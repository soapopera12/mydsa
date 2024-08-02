# 1721. Swapping Nodes in a Linked List 
# https://leetcode.com/problems/swapping-nodes-in-a-linked-list

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapNodes(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        # find the nodes at the kth position from start and end
        ind = 0

        # No need to find the length of the linked list
        # find it using two pointer

        first = last = head

        # find first k
        for i in range(k-1):
            first = first.next
        
        right = first # ahead by k steps

        while right.next:
            last = last.next
            right = right.next
        
        first.val, last.val = last.val, first.val

        return head

        


        