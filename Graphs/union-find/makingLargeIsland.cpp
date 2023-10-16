// Making A Large Island
// https://practice.geeksforgeeks.org/problems/making-a-large-island/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

// disjoint set union
// using unionByRank is better if you want to save space but unionByRank is O(n) time complexity
// if space is not an issue unionBySize is better as it give O(logn) union time complexity
class DSU{
    int n;
    vector<int> rank;
    vector<int> parent;
    vector<int> size;   // unionBySize withh give 0(logn) at the cost of o(n) space complexity
public: 
    
    // initializing DSU
    DSU(int n){
        this -> n = n;
        parent.resize(n+1,0);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        // making each element their own parent
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    
    // find parent method
    int find_parent(int a){
        if(parent[a] == a){
            return a;
        }
        return parent[a] = find_parent(parent[a]);
    }
    
    // combine by rank
    // union by rank O(n)
    void unionByRank(int a,int b){
        int par_a = find_parent(a);
        int par_b = find_parent(b);
        
        if(par_a == par_b){
            return;         // if both already have same ultimate parent
        }
        
        else if(rank[par_a] < rank[par_b]){
            parent[par_a] = par_b;  // why is rank not increased here
        }
        else if(rank[par_b] < rank[par_a]){
            parent[par_b] = par_a;
        }
        else{
            parent[par_b] = par_a;  // randomly b to a can also be a to b
            rank[par_a]++;
        }
    }
    
    // union by size O(log n)
    void unionBySize(int a,int b){
        int up_a = find_parent(a);
        int up_b = find_parent(b);
        
        if(up_a == up_b){
            return;
        }
        
        if(size[up_a] < size[up_b]){
            parent[up_a] = up_b;
            size[up_b] += size[up_a];
        }
        else{
            parent[up_b] = up_a;
            size[up_a] += size[up_b];
        }
        
    }

    int getSize(int i){     
        return size[i];
    }    
    
};

class Solution
{
public:

    int n;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    
    // function to check bounds
    bool isSafe(int i,int j,vector<vector<int>> &grid){
        if(i < 0 || j < 0 || i == n || j == n || grid[i][j] == 0){
            return false;
        }
        return true;
    }
    

    int solve(DSU &ds,int i,int j,vector<vector<int>> & grid){
        
        set<int> s;
        for(int a=0;a<4;a++){
            int nI = i + dx[a];
            int nJ = j + dy[a];
            if(isSafe(nI,nJ,grid)){
                s.insert(ds.find_parent(nI*n + nJ));
                
            }
        }
        
        int sum = 1;
        for(auto it:s){
            sum += ds.getSize(it);
        }
        
        return sum;
        
    }
    
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        // for each 0 in the matrix
        // find the largest connected island - gives TLE
        
        n = grid.size();
        DSU ds(n*n);                        // dsu object created
        vector<pair<int,int>> to_change;    // all 0s that can be changed(pair of i,j)
        
        // constructing the DSU or 2 sets
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    for(int a=0;a<4;a++){
                        int nI = i + dx[a];
                        int nJ = j + dy[a];
                        if(isSafe(nI,nJ,grid)){
                            // i * n + j -> finds element in the matrix
                            // i* n will give the row and j will give the column
                            // this is being calculated for all the 4 directions
                            // current element parent != adjancet element parent(all 4 directions)
                            if(ds.find_parent(i*n + j) != ds.find_parent(nI*n + nJ)){
                                ds.unionBySize(i*n + j ,nI*n + nJ);
                            }
                        }
                    }
                }
                else{
                    to_change.push_back({i,j});
                }
            }
        }
        
        int largestLandSize = 0;
        for(int i=0;i<n;i++){
            largestLandSize = max(largestLandSize,ds.getSize(i));
        }
        
        for(auto it:to_change){
            int i=it.first;
            int j=it.second;
            largestLandSize = max(largestLandSize,solve(ds,i,j,grid));
        }
        
        return largestLandSize;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends