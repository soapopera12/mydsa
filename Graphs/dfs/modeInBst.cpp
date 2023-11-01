// 501. Find Mode in Binary Search Tree
// https://leetcode.com/problems/find-mode-in-binary-search-tree/description/


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

    void solve(TreeNode* root,unordered_map<int,int> &mp) {
        
        if(root == NULL){
            return;
        }

        mp[root->val]++;

        solve(root->left,mp);
        solve(root->right,mp);
    }

    vector<int> findMode(TreeNode* root) {
        // map to keep number of elements
        unordered_map<int,int> mp;
        vector<int> ans;
        solve(root,mp);    
        int maxi = 0;     

        for(auto nodely:mp){
            if(maxi < nodely.second) {
                maxi = nodely.second;
            }
        }

        for(auto nodely:mp) {           // this is how to iterate a map
            if(nodely.second == maxi)  {
                ans.push_back(nodely.first);
            }
        }

        return ans;

        // // for (const auto& pair : mp) {
        // //     int vale = pair.second;
        // //     int temp = pair.first;
        // //     if(vale == pr){
        // //         ans.push_back(temp);
        // //     }
        // // }

        // for (std::map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        //     int key = it->first;
        //     int value = it->second;
        //     if(value == pr){
        //         ans.push_back(key);
        //     }
        // }

        // return ans;
    

    }
};