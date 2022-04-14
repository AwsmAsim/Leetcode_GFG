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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* h = root;
        TreeNode* answer;
        while(h != NULL){
            if(h->val == val){
                return h;
            }else if(h->val > val){
                if(h->left != NULL)
                h = h->left;
                else return NULL;
            }else{
                if(h->right != NULL)
                h = h->right;
                else return NULL;
            }
        }
        
        return NULL;
    }
};