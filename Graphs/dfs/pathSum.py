# 112. Path Sum
# https://leetcode.com/problems/path-sum

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def hasPathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: bool
        """
        # without stack dfs() equation
        res = []
        self.dfs(root, targetSum, res)
        return any(res)             # returns true if even a single element in the res array is true
        # using stack
        # if not root:
        #     return False
        # stack = [(root, root.val)]
        # while stack:
        #     curr, val = stack.pop()
        #     if not curr.left and not curr.right and val == targetSum:
        #         return True
        #     if curr.right:
        #         stack.append((curr.right, val+curr.right.val))
        #     if curr.left:
        #         stack.append((curr.left, val+curr.left.val))
        # return False

    # normal DFS solution
    def dfs(self, root, target, res):
        if root:
            if not root.left and not root.right and root.val == target:
                res.append(True) # if reached leaf and val and val == target
            if root.left:
                self.dfs(root.left, target-root.val, res)
            if root.right:
                self.dfs(root.right, target-root.val, res)


    # DFS with stack solution
    # def dfsStack(self, root, sum):
    #     if not root:
    #         return False
    #     stack = [(root, root.val)]  # pair of root and root.val
    #     while stack:
    #         curr, val = stack.pop()
    #         if not curr.left and not curr.right and val == sum:
    #             return True
    #         if curr.left:
    #             stack.append((curr.left, val+curr.left.val))
    #         if curr.right:
    #             stack.append((curr.right, val+curr.right.val)
    #     return False



