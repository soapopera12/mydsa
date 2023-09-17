class Solution {
public:

    int isValid(vector<int>& i,vector<int>& j){
        if(i[0] == j[0]){
            return true;        //exist in the same row
        }
        if(i[1] == j[1]){   
            return true;        //exist in the same column
        }
        return false;
    }

    int findParent(vector<int> &parent, int node){
        while(parent[node] != node){
            node = parent[node];
        }
        return node;
    }

    void merge(vector<int>& parent, int& componentCount, int node1,int node2){
        int parent1 = findParent(parent,node1);
        int parent2 = findParent(parent,node2);
        if(parent1 != parent2){
            componentCount--;  // if parents are not same we must keep them
            parent[parent1] = parent2;
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        vector<int> parent(n);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        int componentCount = n;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isValid(stones[i],stones[j])){     // stones is not a matrix lol!
                    merge(parent,componentCount,i,j);   //if they has same column or row
                }
            }
        }
        return (n-componentCount);
    }
};