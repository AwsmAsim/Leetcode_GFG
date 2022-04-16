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
    
    int convert(TreeNode* root, int parentValue){
        if(root == NULL) return 0;
        // int debugValue = root->val;
        if(root->right==NULL)
        root->val = parentValue + root->val + convert(root->right, parentValue);
        else
            root->val = root->val + convert(root->right, parentValue);
        // cout << debugValue << "->" << root->val << endl;
        if(root->left != NULL) return convert(root->left, root->val);
        else return root->val;
        // return max(root->val, convert(root->left, root->val));
    }
    
    
    
    TreeNode* convertBST(TreeNode* root) {
        convert(root, 0);
        return root;
    }
};