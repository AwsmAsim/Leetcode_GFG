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
    
    TreeNode* findValidRoot(TreeNode* node, int low, int high){
        if(node==NULL) return NULL;
        if(node->val >= low and node->val <= high) return node;
        if(node->val < low) return findValidRoot(node->right, low, high);
        if(node->val > high) return findValidRoot(node->left, low, high);
        return node;
    }
    
    void trim(TreeNode* node, int low, int high){
        if(node == NULL) return;
        //check Left
        node->left = findValidRoot(node->left, low, high);
        // if(node->left != NULL and node->left->val < low){
        //     node->left = node->left->right;
        // }
        
        node -> right = findValidRoot(node->right, low, high);
        //check Right
        // if(node->right != NULL and node->right->val > high){
        //     node->right = node->right->left;
        // }
        
        if(node->left != NULL) trim(node->left, low, high);
        if(node->right != NULL) trim(node->right, low, high);
        return;
    }
    
    
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* validNode = findValidRoot(root, low, high);
        trim(validNode, low, high);
        return validNode;
    }
};