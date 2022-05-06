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
    
    int getH(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(getH(root->left), getH(root->right));
    }
    
    bool naive(TreeNode* root){
        if(root==NULL) return true;
        
        int lh = getH(root->left), rh = getH(root->right);
        
        if(abs(lh - rh)>1) return false;
        
        int checkL = naive(root->left), checkR = naive(root->right);
        
        if(!checkL || !checkR) return false;
        
        return true;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return naive(root);
    
    }
};