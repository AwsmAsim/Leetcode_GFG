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
    
    TreeNode* addNode(int val, TreeNode* leftChild, TreeNode* rightChild){
        TreeNode* newNode = new TreeNode(val);
        newNode->left = leftChild;
        newNode->right = rightChild;
        return newNode;
    }
    
    void solve(TreeNode* root, int val, int depth){
        
        if(root == NULL) return;
        if(depth == 1){
            root->left = addNode(val, root->left, NULL);
            root->right = addNode(val, NULL, root->right);
            return;
        }
        solve(root->left, val, depth-1);
        solve(root->right, val, depth-1);
        
    }
    
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) return addNode(val, root, NULL);
        solve(root, val, depth-1);
        return root;
        
    }
};