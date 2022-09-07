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
    
        
    void solve(TreeNode* root, string& answer){
        
        if(root == NULL) return;
        
        // printf("%c %c\n", root->val, '0');''
        
            string s = to_string(root->val);
        answer += s;
        // if(root->val >= 0){
        // }
        // answer.push_back(root->val + '0');
        // else{
        //     answer.push_back('-');
        //     cout << abs(root->val) << endl;
        //     cout << answer << endl;
        //     cout << abs(root->val) + '0' << endl;
        //     answer.push_back(abs(root->val) + '0');   
        // }
        // cout << answer << endl;
        if(root-> left == NULL and root-> right == NULL) return;

        answer.push_back('(');
        solve(root->left, answer);
        answer.push_back(')');
        
        if(root->right == NULL) return;
        
        answer.push_back('(');
        solve(root->right, answer);
        answer.push_back(')');
    }
    
    
    
public:
    string tree2str(TreeNode* root) {
        string answer;
        
        solve(root, answer);
        
        return answer;
    }
};