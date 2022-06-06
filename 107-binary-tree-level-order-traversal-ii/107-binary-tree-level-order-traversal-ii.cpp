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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> traversal;
        queue<TreeNode*> q;
        if(root == NULL) return traversal;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                level.push_back(q.front()->val);
                q.pop();
            }
            traversal.push_back(level);
        }
        reverse(traversal.begin(), traversal.end());
        return traversal;
    }
};