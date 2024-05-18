// 310. Minimum Height Trees
// https://leetcode.com/problems/minimum-height-trees

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n == 1 || n == 0) {
            return {0};
        }

        vector<vector<int>> adj(n);             // preparing adj list
        vector<int> degree(n,0);                    // preparing degree to start extracting nodes with degree 1

        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);        
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        // push all nodes with degree 1 into a queue
        queue<int> q;

        for(int i=0; i<n; i++) {

            if(degree[i] == 1) {
                q.push(i);
            }

        }

        vector<int> res;

        while(!q.empty()) {

            res.clear();
            int size = q.size();

            while(size--) {

                int node = q.front();
                q.pop();

                res.push_back(node);

                for(auto &neigh: adj[node]) {
                    degree[neigh]--;
                    if(degree[neigh] == 1) {
                        q.push(neigh);
                    }
                }                               
            }
        }

        return res;
    
    }
};