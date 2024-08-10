# 143. Reorder list
# https://leetcode.com/problems/reorder-list

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        # Get rid of other elements
        if not head and not head.next:
            return head
        
        slow = head
        fast = head

        # while mid-point
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        # detaching lsat element of middle
        middle = slow.next
        slow.next = None
        
        # reversing the rest of the array
        prev = None
        while middle:
            nexty = middle.next
            middle.next = prev
            prev = middle
            middle = nexty
        
        # Merging
        list1 = head
        list2 = prev
        nexty1 = None
        nexty2 = None

        while list1 and list2:
            # nexty like
            nexty1 = list1.next
            nexty2 = list2.next

            # merge
            list1.next = list2
            list2.next = nexty1

            # going forward
            list1 = nexty1
            list2 = nexty2

        return head



