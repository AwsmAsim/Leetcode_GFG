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
    
    int checkAv(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(root == NULL) return 0;
        if(root == p or root == q) return 1;
        
        if(checkAv(root->right, p, q)) return true;
        else if(checkAv(root->left, p, q)) return true;
        
        return false;
        
    }
    
    TreeNode* dailyChallenge(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL) return NULL;
        
        TreeNode* t = dailyChallenge(node->left, p, q);
        if(t != NULL) return t;
        
        int nodesFound = checkAv(node->right, p, q) + checkAv(node->left, p, q);
        if(node == p or node == q){
            if(nodesFound == 1) return node;
        }else{
            if(nodesFound == 2) return node;
        }
        
        t = dailyChallenge(node->right, p, q);
        if(t != NULL) return t;
            
        return NULL;
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dailyChallenge(root, p, q);
        return singleTraversalSolve(root, p, q);
        return inorder(root, p, q);
    }
};