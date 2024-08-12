# 1361. Validate Binary Tree Nodes
# https://leetcode.com/problems/validate-binary-tree-nodes

class Solution(object):
    def validateBinaryTreeNodes(self, n, leftChild, rightChild):
        """
        :type n: int
        :type leftChild: List[int]
        :type rightChild: List[int]
        :rtype: bool
        """
        # solve using DFS for each node and mark childrens as -1 so that
        # if they are visited by others we stop them also
        # and return the number of children for each node to ensure binary atmost 2 
        # solve using iteration

        root = 0
        children_nodes = set(leftChild + rightChild)
        for i in range(n):
            if i not in children_nodes:
                root = i
        
        visited = set()
        queue = deque([root])

        while queue:
            # Push children in 
            # Initiaze a queue and push both children into the queue4
            # check if children are already visited
            curr = queue.popleft()
            if curr in visited:
                return False
            #if visited[leftChild[curr]] == -2 or visited[rightChild[curr]] == -2:
            #    return False
            visited.add(curr)
            
            # processing childrens
            if leftChild[curr] != -1:
                queue.append(leftChild[curr]) # appending only if there is actually a children
            if rightChild[curr] != -1:
                queue.append(rightChild[curr])

        return len(visited) == n        