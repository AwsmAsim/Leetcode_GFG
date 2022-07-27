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
    
    TreeNode* prev;
    
    TreeNode* pred(TreeNode* node){
        if(node == NULL) return NULL;
        if(node->right == NULL) return node;
        return pred(node->right);
    }
    
    void inOrder(TreeNode* node){
        if(node!=NULL){
            if(node->left){
                pred(node->left) -> right = node->right;
                node->right = node->left;
                node->left = NULL;
            }
             inOrder(node->right);
        }
        return;
    }
    
    void traversal(TreeNode* node){
        if(node!=NULL){
            traversal(node->left);
             cout << node->val << ", ";
            traversal(node->right);
        }
    }
    
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        inOrder(root);
        // traversal(root);
    }
};