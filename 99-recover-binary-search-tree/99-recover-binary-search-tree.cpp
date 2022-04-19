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
    
    void inorderInsertion(TreeNode* root, int val1, int val2){
        if(root == NULL) return;
        inorderInsertion(root->left, val1, val2);
        if(root->val == val1) root->val = val2;
        else if(root->val == val2) root->val = val1;
        inorderInsertion(root->right, val1, val2);
    }
    
    void inorder(TreeNode* root, vector<int>& inorderList){
        if(root == NULL) return;
        inorder(root->left, inorderList);
        inorderList.push_back(root->val);
        inorder(root->right, inorderList);
    }
    
public:
    void recoverTree(TreeNode* root) {
        vector<int> inorderList;
        inorder(root, inorderList);
        int val1, val2;
        unordered_map<int, int> unbalanced;
        
        // for(auto a: inorderList) cout << a << " " << endl;
        
        for(int i = 0; i < inorderList.size()-1; i++)
            if(inorderList[i] > inorderList[i+1]){
                val1 = inorderList[i];
                break;
            }
        for(int i = inorderList.size()-1; i > 0; i--)
            if(inorderList[i]<inorderList[i-1]){
                val2 = inorderList[i];
                break;
            }
        
        // cout << "Val1: " << val1 << "Val2: " << val2 << endl;
        
        inorderInsertion(root, val1, val2);
        
        
    }
};