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
public:
    int k1  = 0;
    
    int inOrderTraversal(TreeNode* root){
        if(root!=NULL){
            int l = inOrderTraversal(root->left);
            // cout << "at " << root->val << " l: " << l << endl;
            if(l!=-1) return l;
            --k1;
            if(k1==0) return root->val;
            int r = inOrderTraversal(root->right);
            // cout << "at " << root->val << " r: " << r << endl;
            if(r!=-1) return r;
        }
        return -1;
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        this->k1 = k;
        return inOrderTraversal(root);
    }
};