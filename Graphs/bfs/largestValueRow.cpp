// 515. Find Largest Value in Each Tree Row
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:    

    vector<int> largestValues(TreeNode* root) {
        //apply bfs and find the largest value
        if(root == NULL){
            return{};   // empty vector
        }

        vector<int> ans;
        queue<TreeNode*> que; //  level order traversal
        que.push(root); 

        // can control level using a queue
        while(!que.empty()){
            int levelSize = que.size();
            int maxValLevel = INT_MIN;
            for(int i=0;i<levelSize;i++){
                TreeNode* node = que.front(); // taking an element from the queue
                que.pop();                // one doubt regarding this  
                maxValLevel = max(node->val,maxValLevel);

                if(node->left){
                    que.push(node->left);  // appending for the next level
                }

                if(node->right){
                    que.push(node->right); // appending for the next level
                }
            }
            ans.push_back(maxValLevel);
        }
        return ans;
    }
};