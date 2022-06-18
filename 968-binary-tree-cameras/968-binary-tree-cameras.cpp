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
    int camera = 0;
    int hasNoCamera = -1, hasCamera = 0, noCameraRequired = 1;
    
    int placeCamera(TreeNode* root, bool child){
        
        if(root == NULL) return noCameraRequired;
        
        int left = placeCamera(root->left, true);
        int right = placeCamera(root->right, true);
        if(left == hasNoCamera or right == hasNoCamera){
            ++camera;
            return hasCamera;
        }else if(left == hasCamera or right == hasCamera){
            return noCameraRequired;
        }else{
            if(child){
                return hasNoCamera;
            }else{
                ++camera;
                return hasCamera;
            }
        }
        return 0;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        if(root->left == NULL and root->right == NULL) return 1;
        placeCamera(root, false);
        return camera;
    }
};