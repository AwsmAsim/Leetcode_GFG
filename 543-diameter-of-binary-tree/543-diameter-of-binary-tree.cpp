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
    
    int getDiameter(TreeNode* root, int& maxi){
        if(root == NULL) return 0;
        
        int lh = getDiameter(root->left, maxi), 
            rh = getDiameter(root->right, maxi);
        
        maxi = max(lh + rh, maxi);
        return 1 + max(lh, rh);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
        getDiameter(root, maxi);
        return maxi;
    }
};