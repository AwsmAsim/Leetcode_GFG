class Solution {
public:

    int status(TreeNode* root,int &n){
 
        if(root == NULL){
            return 1;
        }
        
        int l = status (root->left,n);
        int r = status (root->right,n);
        

        if(l==0 || r==0){
            n++;
            return 2;
        }
        
        if(l==2 || r==2){
            return 1;
        }
        
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int n=0;
        
        if(status(root,n) == 0){
            n++;
        }
        return n;
    }
};