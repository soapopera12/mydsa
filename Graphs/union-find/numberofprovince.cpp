

class unionFind {

private:
    vector<int> parent,rank;
    int count;

public:
    unionFind(int n){
        parent.resize(n);
        rank.resize(n);
        count = n;
        for(int i=0;i<n;i++){
            parent[i] = i;  // push parent as itself
        }
    }

    int find(int x){    // function to return ultimate parent
        if(parent[x] != x) parent[x] = find(parent[x]); 
        return parent[x];
    }

    void union_set(int x,int y) {
        int xset = find(x), yset = find(y); // got the ultimate parents
        if(rank[xset] < rank[yset]){
            parent[xset] = yset;    //if they are different parents condition 1
        }
        else if(rank[xset] > rank[yset]){
            parent[yset] = xset;    // condition 2
        }
        else {
            parent[yset] = xset;    
            rank[xset]++;
        }
    }
};

class Solution {
public:

    void dfs(int node,vector<vector<int>>& isConnected, vector<bool>& visit) {
        visit[node] = true; //first mark it as true
        for(int i=0;i< isConnected.size(); i++){   //then visit all the its friends
            if(isConnected[node][i] && !visit[i]){
                // connected and not visited
                dfs(i,isConnected,visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // adjancency matrix is given
        // for every element in this matrix you have to call the union func        
        // parent arr, rank arr
        // this is union find method 
        // int n = isConnected.size();
        // unionFind dsu(n);
        // int numberOfComponents = n;

        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(isConnected[i][j] && dsu.find(i) != dsu.find(j)) {
        //             numberOfComponents--;   // intresting way of finding the number
        //             dsu.union_set(i,j);     // use a small graph of 2 node     
        //         }
        //     }
        // }

        // return numberOfComponents;
            
        // dfs methhod
        // best method lol
        int n = isConnected.size();
        int numberOfComponents = 0;
        vector<bool> visit(n);
    
        for(int i=0;i<n;i++){
            if(!visit[i]) {
                numberOfComponents++;
                dfs(i,isConnected,visit);
            }
        }
        return numberOfComponents;
    }
};