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
    
    int solve(TreeNode* root){
        
        if(root == NULL) return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left == 0) root->left = NULL;
        if(right == 0) root->right = NULL;
        
        
        return max(max(left, right), root->val);
        
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        solve(root);
        if(root->left == NULL and root->right == NULL){
            if(root->val == 0) return root = NULL;
            else return root;
        }
        
        return root;
        
    }
};