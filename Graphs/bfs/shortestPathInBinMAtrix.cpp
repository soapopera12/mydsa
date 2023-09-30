// 1091. Shortest Path in Binary Matrix
// https://leetcode.com/problems/shortest-path-in-binary-matrix/


class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //setting variables
        int n = grid.size();
        int m = grid[0].size();
        int level = 0;
        int dx[]={0,0,1,1,1,-1,-1,-1};
        int dy[]={1,-1,0,1,-1,0,1,-1};

        // false condirion
        if(grid[0][0]){
            return -1;
        }

        queue<pair<int,int>> que;
        que.push({0,0});

        while(!que.empty()){
            int len = que.size();
            level++;        
            while(len--){
                int x = que.front().first;
                int y = que.front().second;

                if(x == n-1 && y == m-1){
                    return level;
                }
                que.pop();
                for(int i = 0;i<8;i++){
                    int nextx = x + dx[i];
                    int nexty = y + dy[i];

                    if(nextx >= 0 && nextx < n && nexty >=0 && nexty < m && grid[nextx][nexty] == 0){
                        grid[nextx][nexty] = 1; // this prevents us from going back to the same direction important
                        que.push({nextx,nexty});
                    }
                }
            }
        }
        return -1;
    }
};