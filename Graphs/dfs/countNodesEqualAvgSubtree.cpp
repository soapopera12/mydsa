// 2265. Count Nodes Equal to Average of Subtree
// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

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
    void findAvg(TreeNode* root, int &total, int &numOfNodes) {

        if(root == NULL) {
            return;
        }

        total = total + root->val;
        numOfNodes = numOfNodes + 1;

        findAvg(root->left,total,numOfNodes);
        findAvg(root->right,total,numOfNodes);        
    }

    // int countNodes(TreeNode* root,int &avg){

    //     if(root == NULL) {
    //         return 0;
    //     }

    //     int count = 0;
    //     if(root->val == avg) {
    //         count = 1;
    //     }

    //     int leftCount = countNodes(root->left,avg);
    //     int rightCount = countNodes(root->right,avg);

    //     return count + leftCount + rightCount;
    // }

    int finalAns(TreeNode* root) {

        if(root == NULL){
            return 0;
        }

        int total = 0;
        int numOfNodes = 0;
        findAvg(root,total,numOfNodes);
        int avg = total / numOfNodes;

        int count = 0;
        if(root-> val == avg) {
            count += 1;
        }

        int left = finalAns(root->left);
        int right = finalAns(root->right);

        return count + left + right;
    }

    pair<int,int> postOrder(TreeNode *root,int& result) {

        if(root == NULL){
            return {0,0};
        }

        auto [leftSum,leftCount] = postOrder(root->left,result);
        auto [rightSum,rightCount] = postOrder(root->right,result);

        int curr_sum = root->val + leftSum + rightSum;
        int curr_count = 1 + leftCount + rightCount;

        if(curr_sum / curr_count == root->val) {
            result++;
        } 

        return {curr_sum,curr_count};

    }

    int averageOfSubtree(TreeNode* root) {
        // find avererage of tree
        // count number of nodes and total
        // count number of elements average of tree
        // avg of each subtree
        //return finalAns(root);
        int result = 0;
        postOrder(root,result);
        return result;
        //return countNodes(root,avg);
    }
};