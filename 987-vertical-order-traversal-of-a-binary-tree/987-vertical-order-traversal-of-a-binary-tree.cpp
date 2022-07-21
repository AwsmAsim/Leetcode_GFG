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
    
    vector<vector<int>> bfsSolve(TreeNode* root){
        
        queue<pair<TreeNode*, pair<int, int>>> Q; // (value, <ColumnNo, rowNo>)
        map<int, map<int, multiset<int>>> tMap;
        vector<vector<int>> answer;
        
        Q.push({root, {0, 0}});
        
        while(!Q.empty()){
            int Qsize = Q.size();
            for(int i = 0; i < Qsize; ++i){
                TreeNode* topNode = Q.front().first;
                int columnNo = Q.front().second.first;
                int rowNo = Q.front().second.second;
                Q.pop();
                if(topNode -> left) Q.push({topNode->left, {columnNo - 1, rowNo + 1}});
                if(topNode -> right) Q.push({topNode->right, {columnNo + 1, rowNo +1}});
                tMap[columnNo][rowNo].insert(topNode->val);
            }
        }
        
        
        for(pair<int, map<int, multiset<int>> > rowMap: tMap){
            vector<int> v;
            for(pair<int, multiset<int>> val: rowMap.second){
                for(int a: val.second){
                    v.push_back(a);
                }
            }
            answer.push_back(v);
        }
        
        return answer;
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        return bfsSolve(root);
    }
};