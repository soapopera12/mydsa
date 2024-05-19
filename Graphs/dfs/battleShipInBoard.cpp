// 419. Battleships in a Board
// https://leetcode.com/problems/battleships-in-a-board

class Solution {
public:
    vector<pair<int,int>> directions ={{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& visited) {
        
        // just need to check once in which direction
        int n = board.size();
        int m = board[0].size();
        stack<pair<int,int>> st;        // you can either use a stack/queue or use recursive calls using visited vector
        st.push({i,j});

        while(!st.empty()) {

            auto [x,y] = st.top();
            st.pop();

            for(auto dir:directions) {

                int nx = x + dir.first;
                int ny = y + dir.second;

                if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny] == 'X' && !visited[nx][ny]) {

                    visited[nx][ny] = 1;
                    st.push({nx,ny});
                    
                }

            }

        }
        
    }

    int countBattleships(vector<vector<char>>& board) {
        
        // call DFS on each X found    
        int n = board.size();
        int m = board[0].size();
        int battleshipCount = 0;
        vector<vector<int>> visited(n, vector<int>(m,0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {

                if(board[i][j] == 'X' & !visited[i][j]) {
                    dfs(i,j,board,visited);
                    battleshipCount++;
                }

            }
        }

        return battleshipCount;
    }
};

// class Solution {
// public:
//     int countBattleships(vector<vector<char>>& board) {
//         int res=0;
//         vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
//         for(int i=0;i<board.size();i++)
//         {
//             for(int j=0;j<board[0].size();j++)
//             {
//                 if(board[i][j]=='X' && vis[i][j]==0)
//                 {
//                     res++;
//                     fun(board,vis,i,j);
//                 }
//             }
//         }
//         return res;
//     }
//     void fun(vector<vector<char>>& board,vector<vector<int>>& vis,int i,int j)
//     {
//         if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || vis[i][j] || board[i][j]!='X')
//             return;
        
//         // if visited vector is being used no need for stack
//         vis[i][j]=1;
//         fun(board,vis,i-1,j);
//         fun(board,vis,i+1,j);
//         fun(board,vis,i,j-1);
//         fun(board,vis,i,j+1);
//     }
// };