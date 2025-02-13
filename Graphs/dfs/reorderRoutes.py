# 1466. Reorder Routes to Make All Paths Lead to the City Zero
# https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

class Solution(object):
    def minReorder(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: int
        """

        def dfs(curr_city):
            change = 0
            visited[curr_city] = True
            for to_city in adj_list[curr_city]:
                if not visited[abs(to_city)]:  # abs is necessay because some values can be less than 0
                    change += dfs(abs(to_city)) + (1 if to_city > 0 else 0)

            return change

        adj_list = [[] for i in range(n)]

        # create adjacency list
        for i in connections:
            city1 = i[0] 
            city2 = i[1]
            adj_list[city1].append(city2)
            adj_list[city2].append(-city1)

        visited = [False] * n

        return dfs(0)

        