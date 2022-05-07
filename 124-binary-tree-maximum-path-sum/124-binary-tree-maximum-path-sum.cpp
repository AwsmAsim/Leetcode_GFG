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
    
    int maxi = INT_MIN;
    
    int getMaxPathSum(TreeNode* root){
        if(root == NULL) return 0;
        
        int lSum = max(0, getMaxPathSum(root->left));
        int rSum = max(0, getMaxPathSum(root->right));
        
        maxi = max(lSum + root->val + rSum, maxi);
        
        return root-> val + max(lSum, rSum);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        getMaxPathSum(root);
        return maxi;
    }
};