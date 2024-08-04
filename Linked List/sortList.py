# 148. Sort List 
# https://leetcode.com/problems/sort-list

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):

    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # merge
        def merge(left, right):
            # merge and join the last elements
            dumbAss = ListNode(-1)
            prev = dumbAss
            # making a new linked list starting from dumbAss

            while left and right:
                if left.val <= right.val:
                    prev.next = left
                    left = left.next
                else:
                    prev.next = right
                    right = right.next
                prev = prev.next
            prev.next = left or right

            return dumbAss.next

        # mergeSort
        def mergeSort(head):

            if not head or not head.next:
                return head

            # find the mid element first
            left = slow = fast = head
            fast = fast.next  # this makes sure we dont go ahead mid

            while fast and fast.next:
                slow = slow.next
                fast = fast.next.next
            
            right = slow.next
            slow.next = None # slow is mid

            left_sorted = mergeSort(left)
            right_Sorted = mergeSort(right)

            return merge(left_sorted, right_Sorted)

        return mergeSort(head)
        
                
        # trying bubble sort
        # current = head

        # while current:
        #     first = head
        #     second = head.next
        #     while second:
        #         if first.val > second.val:
        #             first.val, second.val = second.val, first.val # bubbling
        #         first = second
        #         second = second.next
        #     current = current.next
        
        # return head



            
