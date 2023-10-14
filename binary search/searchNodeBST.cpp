// Search a node in BST
// https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/0

bool search(Node* root, int x) {
    // Your code here
    if(root == NULL){
        return 0;
    }
    else if(root->data == x){
        return 1;
    }
    else if(x > root->data){
        return search(root->right,x);
    }
    else{
        return search(root->left,x);
    }
    
}