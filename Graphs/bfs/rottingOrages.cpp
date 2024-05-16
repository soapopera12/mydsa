// 994. Rotting Oranges
// https://leetcode.com/problems/rotting-oranges

class Solution {
public:

    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int totalOranges, vector<vector<int>>& visited) {

        int time = -1;

        if(q.empty()) {
            return -1;
        }

        while(!q.empty()) {

            int size = q.size();                // to keep track of number of elements in queue
            
            while(size--) {

                // find all 4 directions and if valid and not visited and is a fresh orange spread and push in queue
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

                for(auto dir:directions) {
                    
                    int dx = dir.first + x;
                    int dy = dir.second + y;

                    if(dx>=0 && dx<grid.size() && dy>=0 && dy<grid[0].size() && visited[dx][dy] == 1) {
                        visited[dx][dy] = 2;
                        totalOranges--;
                        q.push(make_pair(dx,dy));
                    }

                }

            }

            time++;
        }

        if(totalOranges == 0) {
            return time;
        }
        return -1;
    }


    int orangesRotting(vector<vector<int>>& grid) {
        
        int totalOranges = 0;
        queue<pair<int,int>> q;
        vector<vector<int>> visited = grid;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push(make_pair(i,j));
                }
                if(grid[i][j] == 1) {
                    totalOranges++;
                }
                
            }
        }

        if (totalOranges == 0)
            return 0;
        if (q.empty())
            return -1;

        return bfs(grid, q, totalOranges, visited);
    }
};