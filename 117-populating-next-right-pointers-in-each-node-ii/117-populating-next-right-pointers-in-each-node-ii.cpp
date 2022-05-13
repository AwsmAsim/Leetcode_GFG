/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/



class Solution {
    
    void levelOrderTraversal(Node* root){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* prev = NULL; 
            int n = q.size();
            for(int i = 0; i < n; i++){
                Node* n = q.front();
                q.pop();
                if(prev!=NULL) prev->next = n;
                if(n->left != NULL)q.push(n->left);
                if(n->right != NULL)q.push(n->right);
                prev = n;
            }
        }
    }
    
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        levelOrderTraversal(root);
        return root;
    }
};