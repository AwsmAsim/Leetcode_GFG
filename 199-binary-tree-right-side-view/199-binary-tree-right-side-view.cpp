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
    vector<int> rightSideView(TreeNode* root) {
        
        if(root == NULL) return {};
        
        queue<TreeNode*> traversalQ;
        vector<int> rightView;
        vector<vector<int>> levelOrderTraversal;
        
        traversalQ.push(root);
        while(!traversalQ.empty()){
            int traversalQSize = traversalQ.size();
            vector<int> levelList;
            for(int i = 0; i < traversalQSize; i++){
                TreeNode* ttop = traversalQ.front();
                levelList.push_back(ttop->val);
                traversalQ.pop();
                if(ttop->left) traversalQ.push(ttop->left);
                if(ttop->right) traversalQ.push(ttop->right);
            }
            levelOrderTraversal.push_back(levelList);
        }
        
        // for(auto level: levelOrderTraversal){
        //     cout << "{";
        //     for(int node: level) cout << node << ", ";
        //     cout << "}" << endl;
        // }
        
        for(auto level: levelOrderTraversal){
            rightView.push_back(level.back());
        }
        
        return rightView;
        
    }
};