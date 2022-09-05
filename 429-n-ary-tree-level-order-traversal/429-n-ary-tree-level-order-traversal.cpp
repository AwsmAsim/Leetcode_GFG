/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return vector<vector<int>>();
        
        queue<Node*> Q;
        Q.push(root);
        vector<vector<int> > answer;
        
        while(!Q.empty()){
            int Qsize = Q.size();
            vector<int> v;
            for(int i = 0; i < Qsize; i++){
                Node* topNode = Q.front();
                Q.pop();
                v.push_back(topNode->val);

                for(Node* child: topNode->children){
                    Q.push(child);
                }
            }
            
            answer.push_back(v);
        }
        
        return answer;
        
    }
};