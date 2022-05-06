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
    
//     int getH(TreeNode* root){
//         if(root == NULL) return 0;
//         return 1 + max(getH(root->left), getH(root->right));
//     }
    
//     bool naive(TreeNode* root){
//         if(root==NULL) return true;
        
//         int lh = getH(root->left), rh = getH(root->right);
        
//         if(abs(lh - rh)>1) return false;
        
//         int checkL = naive(root->left), checkR = naive(root->right);
        
//         if(!checkL || checkR) return false;
        
//         return true;
//     }
    
    int check(TreeNode* root){
        if(root == NULL) return 0;
        
        int lh = check(root->left);
        if(lh == -1) return -1;
        int rh = check(root->right);
        if(rh == -1) return -1;
        
        if(abs(lh - rh) > 1) return -1;
        
        return 1+max(lh, rh);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        int ch = check(root);
        if(ch == -1) return false;
        return true;
    
    }
};