// 1535. Find the Winner of an Array Game
// https://leetcode.com/problems/find-the-winner-of-an-array-game/description/


class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        // // distinct integers in arr

        // // keep a map to track number of wins
        // unordered_map<int,int> wins;
        // // queue to traverse instead of vector
        // queue<int> que;

        // // intitialize all element in the arr to 0
        // for(int i=0;i<arr.size();i++) {
        //     wins[arr[i]] = 0;    // making all elements to 0
        //     que.push(arr[i]);
        // }

        // while(true) {
        //     int n = que.size() - 1;
        //     if(n == 0) {
        //         break;
        //     }
        //     for(int i=0;i<n;i++) {
        //         int first = que.front();
        //         que.pop();
        //         int second = que.front();
        //         if(first > second){
        //             wins[first]++;
        //             if(wins[first] == k){
        //                 return first;
        //             }
        //             que.push(second);
        //         }
        //         else{
        //             wins[second]++;
        //             if(wins[second] == k){
        //                 return second;
        //             }
        //             que.push(first);
        //         }
        //     }

        // }

        // return -1;  

        int winner = arr[0];
        int wins = 0;
        
        for (int i = 1; i < arr.size(); i++) {
            if (winner > arr[i])
                wins++;
            else {
                wins = 1;
                winner = arr[i];
            }
            
            if (wins == k)
                break;
        }
        
        return winner;
        
    }
};