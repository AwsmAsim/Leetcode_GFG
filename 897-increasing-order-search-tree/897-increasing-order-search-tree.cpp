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
    
    void inorder(TreeNode* root, TreeNode*& newRoot){
        if(root == NULL) return;
        inorder(root->left, newRoot);
        TreeNode* newNode = new TreeNode(root->val);
        newRoot -> right = newNode;
        newRoot = newRoot->right;
        // cout << newRoot -> val << "---";
        inorder(root->right, newRoot);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *newRoot = new TreeNode(-1), *ans = newRoot;
        inorder(root, newRoot);
        return ans->right;
    }
};