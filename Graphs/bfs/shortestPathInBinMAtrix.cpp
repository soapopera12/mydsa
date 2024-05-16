// 1091. Shortest Path in Binary Matrix
// https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] == 1) {
            return -1;
        }

        int length = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m,0));

        q.push(make_pair(0,0));
        visited[0][0] = true;

        while(!q.empty()) {
            
            int size = q.size();
            length++;

            while(size--) {

                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(x==n-1 && y==m-1) {
                    return length;
                }

                // diagonal directions
                vector<pair<int,int>> directions = {{1,1},{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1}};

                for(auto dir:directions) {

                    int dx = x + dir.first;
                    int dy = y + dir.second;

                    if(dx>=0 && dx<n && dy>=0 && dy<m && grid[dx][dy]==0 && !visited[dx][dy]) {
                        q.push(make_pair(dx,dy));
                        visited[dx][dy] = true;
                    }
                }

            }

        }

        return -1;

    }
};