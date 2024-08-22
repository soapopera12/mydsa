# 129. Sum Root to Leaf Numbers
# https://leetcode.com/problems/sum-root-to-leaf-numbers/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # trying DFS
        # use stack
        res = 0
        stk = []

        if root:
            stk.append(root)
        
        while stk:
            curr = stk.pop()
            # leaf node condition
            if not curr.left and not curr.right:
                res += curr.val
            # going left
            if curr.left:
                curr.left.val += curr.val * 10
                stk.append(curr.left)
            # going right
            if curr.right:
                curr.right.val += curr.val * 10
                stk.append(curr.right)
        
        return res