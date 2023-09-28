// 1162. As Far from Land as Possible
// https://leetcode.com/problems/as-far-from-land-as-possible/description/

class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {
       // new approach 
       // find all the islands - 1 and add them to a queue
       // now find all the island at distance 1 square from the island
       // now do this again
       // as long as there are 0s in the matrix continue
       // finally when the queue is empty return the last time the queue had elements

        vector<vector<int>> visited = grid;
        queue <pair<int,int>> que;
        // push all 1s int the queue
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(visited[i][j] == 1){
                    que.push({i,j});
                }
            }
        }

       //check length of queue for -1 case
       if(que.empty() || que.size() == grid.size() * grid.size()){
           return -1;
       }
        int distance = -1;  // distance increases by 1 
        vector<pair<int, int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!que.empty()){
            int size = que.size();
            while(size--){  // doing this for every 1 in the matrix 
                auto [x,y] = que.front();
                que.pop();
                for(auto [dx,dy] : directions){
                    int i = x + dx;
                    int j = y + dy;
                    if(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && visited[i][j] == 0){
                        visited[i][j] = 1;
                        que.push({i,j});
                    }
                }
            }
            distance++; // increasing distance by 1
        }
        return distance;
    }
};