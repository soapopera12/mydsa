# 988. Smallest String Starting From Leaf
# https://leetcode.com/problems/smallest-string-starting-from-leaf/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def smallestFromLeaf(self, root):
        """
        :type root: TreeNode
        :rtype: str
        """
        # suppose the two strings are s1="ab" , s2="abcdef" 
        # in this case where s1 is a prefix of s2 or vice versa, BY DEFINITION , 
        # the string with smaller size will be lexicographically smaller than 
        # the other. (in this case s1 is lexicographically smaller than s2).
        paths = []
                
        def dfs(node, string):
            string += chr(node.val + 97) # we only call dfs is if the node is present so no attribute error
            if node.left:               
                dfs(node.left, string)
            if node.right:
                dfs(node.right, string)
            
            if not node.right and not node.left:
                paths.append(string[::-1]) # reverse of string
            
        dfs(root, '')
        paths.sort() # we get all the possible strings and then sort them

        return paths[0]

        # # Fails for testcase [25,1,null,0,0,1,null,null,null,0]
        # # Since the Note is you dont have to see the length of the string instead one have to see the smallest from begining. since s=ababz and t=abz s[2]<t[2] so s is smaller here
        # # scrapping 

        # # return leaf node val
        # if not root.left and not root.right:
        #     return chr(root.val + 97)

        # # should work in string not numbers
        # left_val, right_val = chr(200), chr(200) # like +inf

        # if root.left:
        #     left_val = self.smallestFromLeaf(root.left) + chr(root.val + 97)

        # if root.right:
        #     right_val = self.smallestFromLeaf(root.right) + chr(root.val + 97)

        # if left_val < right_val:
        #     ans = left_val
        # else:
        #     ans = right_val

        # return ans

        # class Solution:
        #     def smallestFromLeaf(self, root: TreeNode) -> str:
        #         paths = []
                
        #         def dfs(node, string):
        #             # Translate node value to letter via ASCII
        #             string += chr(node.val + 97)
                    
        #             if node.left: dfs(node.left, string)
        #             if node.right: dfs(node.right, string)
        #             # At leaf node, add reversed tree path to "paths"
        #             if not node.right and not node.left: paths.append(string[::-1])
                        
        #         dfs(root, '')
        #         # Sort in lexicographical order and return first path
        #         paths.sort()
        #         return paths[0]