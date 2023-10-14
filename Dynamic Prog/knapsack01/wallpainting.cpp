// 2742. Painting the Walls
// https://leetcode.com/problems/painting-the-walls/description/


class Solution {
public:


    // int dp[501][501] = {};

    // int solve(int remainingWalls,int curr,vector<int> &cost, vector<int> &time){

    //     if(remainingWalls <= 0){
    //         return 0;
    //     }

    //     if(curr >= cost.size()){
    //         return 1000000000;
    //     }

    //     if(dp[curr][remainingWalls] != 0){
    //         return dp[curr][remainingWalls];
    //     }

    //     int not_take = solve(remainingWalls,curr+1,cost,time);  // situation of free painter

    //     //situation of other painter
    //     int take = cost[curr] + solve(curr+1,remainingWalls -time[curr] - 1,cost,time);
        

    //     return dp[curr][remainingWalls] = min(take,not_take);      

    // }


    // int paintWalls(vector<int>& cost, vector<int>& time) {
        
    //     // solve using dp
    //     return solve(0,time.size(),cost,time);

    // }


    int dp[501][501] = {};

int solve(vector<int>& cost, vector<int>& time, int i, int wallReamining){
    if(wallReamining <= 0) return 0;
    if(i >= cost.size()) return 1000000000;
    if(dp[i][wallReamining] != 0) return dp[i][wallReamining];
    int notTake = solve(cost, time, i+1, wallReamining);
    int take = cost[i] + solve(cost, time, i+1, wallReamining -  time[i] -1); 
    return dp[i][wallReamining] = min(notTake, take);      
}



    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        // solve using dp
        return solve(cost, time, 0, time.size());

    }
};
