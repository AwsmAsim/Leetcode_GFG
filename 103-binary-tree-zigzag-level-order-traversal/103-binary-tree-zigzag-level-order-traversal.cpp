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
    
    void printQueue(queue<TreeNode*> q){
        while(!q.empty()){
            cout << q.front()->val << ", ";
            q.pop();
        }
        cout << "\n";
    }
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> answer;
        if(root == NULL) return answer;
        
        bool leftToRight = true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            // printQueue(q);
            // cout << "size: " << n << endl;
            vector<int> v(n);
            for(int i = 0; i < n; i++){
                if(leftToRight) v[i] = (q.front()->val);
                    else v[n - i - 1] = q.front()->val;
                if(q.front()->left!=NULL)  q.push(q.front()->left);
                if(q.front()->right!=NULL) q.push(q.front()->right);
                q.pop();
            }
            leftToRight = !leftToRight;
            answer.push_back(v);
        }
        
        return answer;
    }
};