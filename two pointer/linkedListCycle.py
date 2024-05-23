# 141. Linked List Cycle
# https://leetcode.com/problems/linked-list-cycle

# # Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        dictionary = {}
        while head:
            if head in dictionary:
                return True
            else:
                dictionary[head] = True
            head = head.next
        return False

        # if not head:
        #     return False

        # slow = head
        # fast = head.next

        # while slow != fast:
        #     if not fast or not fast.next:
        #         return False
        #     slow = slow.next
        #     fast = fast.next.next
        # return True