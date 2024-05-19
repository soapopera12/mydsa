// 934. Shortest Bridge
// https://leetcode.com/problems/shortest-bridge

class Solution {
    vector<vector<int> > mat;
    vector<vector<int> > vis;
    int m,n;
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};
    queue<pair<int,int> > que;
public:
    void dfs(int i,int j){
        vis[i][j]=1;
        que.push({i,j});
        for(int dir=0;dir<4;dir++){
            int xd=i+x[dir];
            int yd=j+y[dir];
            if(xd>=0 && yd>=0 && xd<=m-1 && yd<=n-1){
                if(!vis[xd][yd] && mat[xd][yd]==1){
                    dfs(xd,yd);
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        m=A.size();
        if(m==0) return 0;
        n=A[0].size();
        cout<<m<<" "<<n;
        mat=A;
        vis.resize(m,vector<int>(n,0));
        int flag=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    dfs(i,j);
                    flag=1;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        int l=0;
        while(!que.empty()){
            int len=que.size();
            l++;
            while(len--){
                pair<int,int> poi=que.front();
                que.pop();
                vis[poi.first][poi.second]=1;
                for(int dir=0;dir<4;dir++){
                    int xd=poi.first+x[dir];
                    int yd=poi.second+y[dir];
                    if(xd>=0 && yd>=0 && xd<=m-1 && yd<=n-1){
                       if(!vis[xd][yd] && mat[xd][yd]==1){
                           return l-1;
                       }
                       else if(!vis[xd][yd] && mat[xd][yd]==0){
                           vis[xd][yd]=1;
                           que.push({xd,yd});
                       }
                    }
                }
            }
        }
        return -1;
    }
};      


// class Solution {
// public:
//     vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

//     bool isValid(int x, int y, vector<vector<char>>& grid, vector<vector<char>>& visited) {
        
//         int n = grid.size();
//         int m = grid[0].size();

//         // within boundaries not visited yet and is part of a land mass
//         if(x >= 0 && y >= 0 && x<n && y<m && grid[x][y] == 1 && visited[x][y] == 0) {
//             visited[x][y] = 1;
//             return true;
//         }

//         return false;
//     }

//     void bfsMakeTwo(int i, int j, vector<vector<int>>& grid, int &ans) {
        
//         queue<pair<int,int>> coloring; // will be used later
//         queue<pair<int,int>> q;
//         q.push({i,j});
//         coloring.push({i,j});
//         visited<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),0));

//         while(!q.empty()) {
            
//             pair<int,int> current = q.front();

//             for(auto dir:directions) {

//                 int x = current.first + dir.first;
//                 int y = current.second + dir.second;
            
//                 if(isValid(x, y, grid, visited)) {
//                     coloring.push({x,y});
//                     grid[x][y] = 2;
//                     q.push({x,y});
//                 }

//             }
//         }

//         // one island is now 2 
//         // Connect layer by layer to another island
//         int n = grid.size();

//         while(!coloring.empty()) {

//             int size = coloring.size();
//             ans++;
//             while(size--) {

//                 int current = coloring.front();

//                 for(auto dir:directions) {
                    
//                     int x = current.first + dir.first;
//                     int y = current.second + dir.second;

//                     // check bounds
//                     if(x >=0 && x < n && y >=0 && x < n) {

//                         if(grid[i][j] == 1) {
                            
//                         }

//                         if(grid[i][j] == 0) {
//                             // grid[i][j] + 1
//                             grid[x][y] = 2;
//                             q.push({x,y});
//                         }

//                     }

//                 }
//                 // for zero (old island value + 1) 
//                 // for 1 update minimumDistance

//             }

//         }      
//     }


//     int shortestBridge(vector<vector<int>>& grid) {
        
//         int n = grid.size();

//         int ans = 0;
//         // make one island numbering to 2
//         for(int i=0; i<n; i++) {
//             for(in j=0; j<n; j++) {
//                 if(grid[i][j] == 1) {
//                     bfsMakeTwo(i,j,grid,ans);
//                     break;
//                 }
//             }

//             if(ans) {
//                 break;
//             }
//         }

//         return ans;
//     }
// }; 