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
    
    map<TreeNode*, int> hMap;
    
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        if(hMap.find(root) != hMap.end()) return hMap[root];
        
        int left = solve(root->left);
        int right = solve(root->right);
        int notPick = left + right;
        
        int pick = root->val;
        if(root->left) pick += solve(root->left->left) + solve(root->left->right);
        if(root->right) pick += solve(root->right->left) + solve(root->right->right);
        
        return hMap[root] = max(notPick, pick);
    }
    
    int include = 0, exclude = 1;
    // [include, exclude]
    vector<int> solveIncExc(TreeNode* root){
        // return max([left.exlucde + right.exclude + curret, left+right])
        
        if(root == nullptr) return vector<int>(2,0);
        
        // cout << root -> val << endl;
        vector<int> left = solveIncExc(root->left);
        vector<int> right = solveIncExc(root->right);
        int notPick = max(left[0], left[1]) + max(right[0], right[1]);
        
        return {left[exclude] + right[exclude] + root->val, notPick};
        
    }
    
public:
    int rob(TreeNode* root) {
        if(root->left == NULL and root->right == NULL) return root->val;
        vector<int> ans = solveIncExc(root);
        return max(ans[0], ans[1]);
        return solve(root);
    }
};