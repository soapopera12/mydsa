// 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions

class Solution {
public:

    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 || j==0 || i==(n-1) || j==(m-1)) {
                    if(board[i][j] == 'O') {
                        q.push({i,j});
                        visited[i][j] = 1;
                    }
                }
            }
        }

        while(!q.empty()) {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            vector<pair<int,int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

            for(auto dir:directions) {
                
                int ix = x + dir.first;
                int ij = y + dir.second;

                if(ix >= 0 && ix < n && ij >= 0 && ij < m && board[ix][ij] == 'O' && !visited[ix][ij]) {
                    visited[ix][ij] = 1;
                    q.push({ix,ij});
                }
            }

        }


        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }

    }
};