# 1519. Number of Nodes in the Sub-Tree With the Same Label
# https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

class Solution(object):
    def countSubTrees(self, n, edges, labels):
        """
        :type n: int
        :type edges: List[List[int]]
        :type labels: str
        :rtype: List[int]
        """
        # should i make adjacency list?
        adj = [[] for i in range(n)]  # made i

        for a,b in edges:       # constructed adjacency list
            adj[a].append(b)
            adj[b].append(a)

        count = [0] * len(string.ascii_lowercase)
        answer = [0] * n

        def dfs(node, parent):
            index = ord(labels[node]) - ord('a')
            previous = count[index]

            count[index] += 1

            for child in adj[node]:
                if child != parent:
                    dfs(child, node)
            
            answer[node] = count[index] - previous  # to separate global count from local count

        dfs(0,-1)

        return answer







