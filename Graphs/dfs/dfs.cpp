// DFS of Graph
// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.

    void solve(int node,vector<int> & ans,vector<int> & visited,vector<int> adj[]){
        //void solve(int node,vector<int> & ans,vector<int> & visited,vector<int> &adj[]){
        //you cannot pass address of adj here
        //because it is an array of an arrary
        ans.push_back(node);
        visited[node] = 1;
        for(auto it : adj[node]){
        
            if(visited[it] == 0){
                solve(it,ans,visited,adj);
            }
            
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        // no need for stack
        vector<int> visited(V,0);
        vector<int> ans;
        solve(0,ans,visited,adj);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends