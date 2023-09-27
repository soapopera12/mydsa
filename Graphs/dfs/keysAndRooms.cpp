// 841. Keys and Rooms
// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    // ran in first attempt - hehe
    // traverse through the rooms in dfs
    void dfs(int node, vector<vector<int>> & rooms, vector<int> & visited){
        
        if(visited[node] == 1){ //simply return if there is nothing
            return;               // maybe this is not required if implemented inside for loop
        }                       

        visited[node] = 1;          // mark it as visited
        for(auto i : rooms[node]){  // find all the avail keys 
            //availRooms[i] = 1;
            dfs(i, rooms, visited);   
        }

        return;
    }


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // mantain a visited array
        // mantain another array to keep the avaiable rooms in check
        // start dfs on 0 room index
        // for all the keys found in it do recursive dfs if it is not visited
        // if all elements are visited in array return true

        // if(rooms.size() == 0 || rooms[0].size() == 0){
        //     return false;   // what to return?
        // }
        
        vector<int> visited(rooms.size(),-1);      // visited array
        //vector<int> availRooms(rooms.size(),-1);   // available rooms
        //availRooms[0] = 1;                         // marking 1st rooms as available
        dfs(0,rooms,visited);

        // check if all rooms are visited
        for(int i=0;i<visited.size();i++){
            if(visited[i] != 1){
                return false;   // if a single room is unvisited
            }
        }
        return true;            

    }
};