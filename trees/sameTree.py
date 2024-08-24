# 100. Same tree
# https://leetcode.com/problems/same-tree/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        # using recursion
        if not p and not q:
            return True
        
        if not p or not q:
            return False
        
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right) and p.val == q.val
        # Iterative using two queues
        # queue = deque()
        # queue.append((p, q))

        # while queue:
        #     node1, node2 = queue.popleft() # try popleft()
        #     if not node1 and not node2:
        #         continue
        #     elif not node1 or not node2:
        #         return False
        #     else:
        #         if node1.val != node2.val:
        #             return False
        #         queue.append((node1.left, node2.left))
        #         queue.append((node1.right, node2.right))
            
        # return True

