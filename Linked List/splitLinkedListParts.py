# 725. Split Linked List in Parts
# https://leetcode.com/problems/split-linked-list-in-parts

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def splitListToParts(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        # split the linked list into a total of k parts
        # keeping all the list size as same as possible
        
        # find the length of the linked list
        length = 0
        temp = head
        
        while temp:
            length += 1
            temp = temp.next
        
        # now you have length so calculate elements in each partition
        ele_each_part = length // k
        # find the extra elements
        remainder =  length % k

        res = []

        temp = head

        for i in range(k):
            curr_part_size = (ele_each_part + 1) if remainder > 0 else (ele_each_part)
            remainder -= 1
            res.append(temp)
            for j in range(curr_part_size - 1):  # -1 because we dont do temp = temp.next for the last node
                temp = temp.next
            if temp:
                temp.next, temp = None, temp.next
            
        return res
            