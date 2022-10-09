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
    
    TreeNode* mainRoot;
    
    bool search(int key, TreeNode* root){
        if(root == NULL) return false;
        if(root->val == key) return true;
        if(root->val > key) return search(key, root->left);
        else return search(key, root->right); 
    }
    
    bool solve(TreeNode* root, int k){
        
        if(root==NULL) return false;
        if(k-(root->val) != root->val and search(k - (root->val), mainRoot)) return true;
        if(solve(root->left, k)) return true;
        if(solve(root->right, k)) return true;
        
        return false;
    }
    
    
public:
    bool findTarget(TreeNode* root, int k) {
        mainRoot = root;
        return solve(root, k);
    }
};