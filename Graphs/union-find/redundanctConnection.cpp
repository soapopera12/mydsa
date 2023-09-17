

// class unionFind {

// private:
//     vector<int> parent,rank;
//     int count;

// public:
//     unionFind(int n){
//         parent.resize(n);
//         rank.resize(n);
//         count = n;
//         for(int i=0;i<n;i++){
//             parent[i] = i;  // push parent as itself
//         }
//     }

//     int find(int x){    // function to return ultimate parent
//         if(parent[x] != x) parent[x] = find(parent[x]); 
//         return parent[x];
//     }

//     void union_set(int x,int y) {
//         int xset = find(x), yset = find(y); // got the ultimate parents
//         if(rank[xset] < rank[yset]){
//             parent[xset] = yset;    //if they are different parents condition 1
//         }
//         else if(rank[xset] > rank[yset]){
//             parent[yset] = xset;    // condition 2
//         }
//         else {
//             parent[yset] = xset;    
//             rank[xset]++;
//         }
//     }
// };


// class Solution {
// public:


//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         // remove an edge to make it a tree
//         int n = edges.size();
//         unionFind dsu(n); 
//         //now for each edge start building the tree
//         vector<int> ans(2,0);

//         for(int i=0;i<n;i++) {
//             int u = edges[i][0];
//             int v = edges[i][1];

//             if(dsu.find(u) == dsu.find(v)){
//                 ans[0] = u;
//                 ans[1] = v;
//             }
//             else {
//                 dsu.union_set(u,v);
//             }
//         }
//         return ans;
//     }
// };

// not working code don't know why

class DisjointSet {
    public: 
        vector<int> parent;
        DisjointSet(int n) {
            parent.resize(n+1);

            for(int i=0;i<n;i++) {
                parent[i] = i;
            }
        }

        int findUPar(int node) {
            if(parent[node] == node)
                return node;

            return parent[node] = findUPar(parent[node]);
        }

        void unionBySmallerSize(int u,int v) {
            int ultU = findUPar(u);
            int ultV = findUPar(v);

            if(ultU == ultV)
                return;

            if(ultU < ultV) {
                parent[ultV] = ultU;
            }
            else {
                parent[ultU] = ultV;
            }
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DisjointSet ds(n);
        vector<int> ans;

        for(int i=0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];


            if(ds.findUPar(u) == ds.findUPar(v)) {
                ans.push_back(u);
                ans.push_back(v);
            } 
            else {
                ds.unionBySmallerSize(u,v);
            }
        }

        return ans;
    }
};