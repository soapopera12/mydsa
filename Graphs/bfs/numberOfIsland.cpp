// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands

class Solution {
public:

    bool isValid(int x, int y, vector<vector<char>>& grid, vector<vector<char>>& visited) {
        
        int n = grid.size();
        int m = grid[0].size();

        // within boundaries not visited yet and is part of a land mass
        if(x >= 0 && y >= 0 && x<n && y<m && grid[x][y] == '1' && visited[x][y] == '0') {
            visited[x][y] = '1';
            return true;
        }

        return false;
    }

    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<char>>& visited) {

        // In all directions check if there is water or land
        // for land call add in queue and repeat here itself simultaneously marking them visited

        visited[i][j] = '1';
        
        queue<pair<int,int>> q;

        q.push({i,j});

        while(!q.empty()) {
            // no need to go layer by layer

            pair<int,int> current = q.front();
            q.pop();

            // get the directions
            vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

            for(auto dir:directions) {
                int x = current.first + dir.first;
                int y = current.second + dir.second;

                // check if this is valid
                if(isValid(x,y,grid,visited)) {
                    q.push({x,y}); 
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int numberOfIslands = 0;
        vector<vector<char>> visited(n, vector<char>(m, '0'));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1' && visited[i][j] == '0') {
                    bfs(i, j, grid, visited);
                    numberOfIslands++;
                }
            }
        }

        return numberOfIslands;
    }
};