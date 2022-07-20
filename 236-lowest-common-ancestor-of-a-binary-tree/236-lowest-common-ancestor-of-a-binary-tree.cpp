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
public:

    int checkAvailablity(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return 0;
        
        if(root == p or root == q) return 1;
        
        if(checkAvailablity(root->left, p, q)) return 1;
        else if(checkAvailablity(root->right, p, q)) return 1;
        
        return 0;
        
    }
    
    // Space complexity: O(N^2)
    TreeNode* inorder(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root!= NULL){
            TreeNode* lAnswer = inorder(root->left, p, q);
            if(lAnswer != NULL ) return lAnswer;
            
            int avail = 0;
            if(root == p or root == q){
                avail = checkAvailablity(root->left, p, q) + checkAvailablity(root->right, p, q);
                if(avail == 1) return root;
            }else{
                avail = checkAvailablity(root->left, p, q) + checkAvailablity(root->right, p, q);
                if(avail == 2) return root;
            }
                
            TreeNode* rAnswer = inorder(root->right, p, q);
            if(rAnswer!=NULL) return rAnswer;
        }
        
        return nullptr;
    }
    
    TreeNode* singleTraversalSolve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return nullptr;
        if(root == p || root == q) return root;
        
        TreeNode* lh = singleTraversalSolve(root->left, p, q);
        TreeNode* rh = singleTraversalSolve(root->right, p, q);
        
        if(lh == NULL) return rh;
        if(rh == NULL) return lh;
        
        return root;
        
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return inorder(root, p, q);
    }
};