// https://practice.geeksforgeeks.org/problems/union-find/1
// Union-Find

class Solution
{
    public:
    int findParent(int par[], int node){
        //if current element is the parent of its own+
        if(node == par[node])
            return node;
            
        //also save in the parent vector
        return par[node] = findParent(par,par[node]);
    }
    
    //Function to merge two nodes a and b.
    void union_( int a, int b, int par[], int rank[]) 
    {
        //code here
        //trying union by rank
        int ulp_a = findParent(par,a);  //find the top most parent
        int ulp_b = findParent(par,b);  //find the top most parent
        
        //check if their parents are same
        if(rank[ulp_a] > rank[ulp_b]){
            par[ulp_b] = ulp_a;         //merging b into a
        }
        else if(rank[ulp_a] <rank[ulp_b]){
            par[ulp_a] = ulp_b;         // no need to increase rank here
        }
        else{
            par[ulp_a] = ulp_b;
            rank[ulp_b]++;              
        }
        
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        //code here
        int ulp_x = findParent(par,x);
        int ulp_y = findParent(par,y);
        
        if(ulp_x == ulp_y){
            return true;
        }
        else{
            return false;
        }
        
        
        
    }