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
    
    int getHeight(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    
    int getDiameter(TreeNode* root){
        if(root == NULL) return 0;
        
        int lh = getHeight(root->left), 
            rh = getHeight(root->right);
        
        return max(lh+rh, 
                   max(getDiameter(root->left), getDiameter(root->right))
                  );
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return getDiameter(root);
    }
};