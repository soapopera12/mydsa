// 1361. Validate Binary Tree Nodes
// https://leetcode.com/problems/validate-binary-tree-nodes/description/

class Solution {
public:

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // prepare adjacency list
        // prepare indegree array - parents each node has
        // check for root candidate - indegree should be 0
        // perform bfs to check for binary tree

        unordered_map<int, vector<int>> graph;   // adjacecy matrix using map
        vector<int> in_degree(n,0);             // indegree vector

        for(int node=0; node<n; node++){
            int left = leftChild[node];
            int right = rightChild[node];
            
            if(left != -1) {
                graph[node].push_back(left);
                in_degree[left]++;
            }

            if(right != -1) {
                graph[node].push_back(right);
                in_degree[right]++;
            }
        }

        vector<int> root_candidates;

        for(int node=0;node<n;node++) {         // finding root candidates
            if(in_degree[node] == 0) {
                root_candidates.push_back(node);
            }
        }

        if(root_candidates.size() != 1){
            return false;
        }

        int root = root_candidates[0];

        queue<int> q;
        unordered_set<int> seen;

        q.push(root);
        seen.insert(root);

        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            if(graph.find(node) != graph.end()) {
                for(int child :graph[node]){
                    if(seen.find(child) != seen.end()){
                        return false;
                    }
                    seen.insert(child);
                    q.push(child);
                }
            }
        }

        return seen.size() == n;
    }
};