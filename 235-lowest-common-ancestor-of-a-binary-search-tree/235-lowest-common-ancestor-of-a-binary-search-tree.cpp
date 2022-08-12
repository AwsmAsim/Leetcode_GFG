/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    
    TreeNode* dailyChallenge(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(root == NULL) return NULL;
        if(root == p) return p;
        if(root == q) return q;
        
        TreeNode* left = dailyChallenge(root->left, p, q);
        TreeNode* right = dailyChallenge(root->right, p, q);
        
        if(left == NULL) return right;
        if(right == NULL) return left;
        
        return root;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dailyChallenge(root, p, q);   
    }
};