// 542. 01 Matrix
// https://leetcode.com/problems/01-matrix/

// class Solution {
// public:

//     // void bfs(int i ,int j ,int distance ,vector<vector<int>>& mat ,vector<vector<int>>& ans){
//     //     // bfs vector
        
//     //     //case where one of the neighbours is not 1
//     //     if(mat[i-1][j] != 1 || mat[i][j-1] != 1 || mat[i+1][j] != 1 || mat[i][j+1] != 1){
//     //         ans[i][j] = distance + 1;
//     //     }

//     //     // either they are completely surrounded by 1s in that case u can find the minimum
//     //     bfs(i-1,j,distance,mat,ans);
//     //     bfs(i,j-1,distance,mat,ans);
//     //     bfs(i+1,j,distance,mat,ans);
//     //     bfs(i,j+1,distance,mat,ans);


//     //     // find all 4 neighbours if any of them is 0 return current length
//     // }

//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

//         if(mat.empty() || mat[0].empty()){
//             return mat;
//         }

//         int n = mat.size();
//         int m = mat[0].size();
//         vector<vector<int>> ans(n,vector<int>(m,0));
//         queue <pair<int,int>> que;
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(mat[i][j] == 0){
//                     que.push({i,j});
//                 }
//                 else{
//                     ans[i][j] = INT_MAX;
//                 }
//             }
//         }
        
//         // distance vector
//         vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
//         // doing dfs from all the positions that hacve 0 in them
        
//         while(!que.empty()){
//             auto cell = que.front();
//             int x = cell.first;
//             int y = cell.second;
            
//             for(auto dir : directions){
//                 int nx = x + dir.first;
//                 int ny = y + dir.second;

//                 if(nx >= 0 && nx < n && ny >=0 && ny < y ){
//                     if( ans[nx][ny] > ans[x][y] + 1){
//                         ans[nx][ny] = ans[x][y] + 1;
//                         que.push({nx,ny}); // why am i pushing this
//                     }
//                 }
//             }

//         }

//         return ans;



//         // // simple program just apply bfs finding 0
        
//         // // ans vector
//         // vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),-1)
//         // //visited array

//         // for(int i=0;i<mat.size();i++){
//         //     for(int j=0;j<mat[0].size();j++){
//         //         if(mat[i][j] == 0){
//         //             // no need to search just 0
//         //             ans[i][j] = 0;
//         //         }
//         //         else{
//         //             // in case it is one find a 0 using bfs - because nearest
//         //             bfs(i,j,0,mat,ans);

                    

//         //         }
//         //     }
//         // }


//     }
// };

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return matrix;
        }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> distances(rows, vector<int>(cols, 0));
        queue<pair<int, int>> q;                    // for bfs a queue is always required in case of matrix
        
        // Enqueue all 0 cells and set their distances to 0
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                } else {
                    distances[i][j] = INT_MAX;
                }
            }
        }
        
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Perform BFS to calculate distances
        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            int x = cell.first;
            int y = cell.second;
            for (auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    if (distances[nx][ny] > distances[x][y] + 1) {
                        distances[nx][ny] = distances[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return distances;
    }
};
