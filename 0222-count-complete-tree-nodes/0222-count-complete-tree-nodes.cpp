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
    
    
    bool hasLastRightNode(TreeNode* root){
        if(root->left == NULL) return true;
        if(root->left and root->right == NULL) return false;
        return hasLastRightNode(root -> right);
    }
    
    int getHeight(TreeNode* root){
        if(root == NULL) return 0;
        
        int left = getHeight(root->left);
        // int right = getHeight(root->right);
        
        return 1+ left;
    }
    
    int naive(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + naive(root-> left) + naive(root->right);
    }
    
    int countNodes(TreeNode* root) {
        
        if(root == NULL) return 0;
        return naive(root);
        if(root->right == NULL and root -> left == NULL) return 1; 
        return (pow(2, getHeight(root)) - 2 + hasLastRightNode(root));
        
    }
};