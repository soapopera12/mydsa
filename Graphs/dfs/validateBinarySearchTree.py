# 98. Validate Binary Search Tree
# https://leetcode.com/problems/validate-binary-search-tree

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        q = deque([])

        q.append((root, float("-inf"), float("inf")))

        while q:
            curr, min_val, max_val = q.popleft()

            if curr:
                if min_val >= curr.val or curr.val >= max_val:
                    return False
                    
                if curr.left:
                    q.append((curr.left, min_val, curr.val))
                
                if curr.right:
                    q.append((curr.right, curr.val, max_val))
                
        return True
             



        


