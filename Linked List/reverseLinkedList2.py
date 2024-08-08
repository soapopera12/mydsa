# 92. Reverse Linked List II 
# https://leetcode.com/problems/reverse-linked-list-ii/description/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """

        if left == right:
            return head
        

        dummyNode = ListNode(0)

        # this saves from boundary condition when left = 1
        dummyNode.next = head
        prev = dummyNode

        # Just reach outside the start loop
        for i in range(left - 1):
            prev = prev.next

        reverse = None
        curr = prev.next

        # + 1 because we are using range
        for i in range(right - left + 1):
            nexty = curr.next
            curr.next = reverse
            reverse = curr
            curr = nexty
        
        prev.next.next = curr
        prev.next = reverse

        return dummyNode.next 


        
        
      