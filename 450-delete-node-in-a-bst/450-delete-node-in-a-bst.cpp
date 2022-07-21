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
    
    TreeNode* head;
    
    TreeNode* successor(TreeNode* root){
        if(root->left == NULL) return root;
        return successor(root->left);
    }
    
    TreeNode* solve(TreeNode* root, int key){
        if(root == NULL) return NULL;
        if(root->val == key){
            
            if(root->left==NULL and root->right == NULL) return NULL;
            if(root->left == NULL and root->right != NULL){
                root->val = successor(root->right)->val;
                root->right = solve(root->right, root->val);
                return root;
            }
            if(root->left != NULL and root->right == NULL){
                if(root == head){
                    head = root->left;
                }
                return root->left;
            }
            if(root->left != NULL and root->right!=NULL){
                TreeNode* success = successor(root->right);
                root->val = success->val;
                root->right = solve(root->right, root->val);
                return root;
            }
        }else if(root->val < key) root->right = solve(root->right, key);
        else root->left = solve(root->left, key);
        
        return root;
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        head = root;
        return solve(root, key);    
    }
};