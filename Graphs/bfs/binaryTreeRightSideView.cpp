// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view

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

    void bfs(TreeNode* root, vector<int>& ans) {

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {

            int size = q.size();

            for(int i=size; i>0; i--) {
                
                TreeNode* temp = q.front();
                q.pop();
                
                if(i == size) {                 // why the fuck is this required
                    ans.push_back(temp->val);
                }

                if(temp->right != NULL) {
                    q.push(temp->right);
                }

                if(temp->left != NULL) {
                    q.push(temp->left);
                }
            } 
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        
        // call BFS on the right side and add elements to the vector

        if(root == NULL) {
            return {};
        }

        vector<int> ans;

        bfs(root, ans);      // call bfs on the right node

        return ans;
    }
};