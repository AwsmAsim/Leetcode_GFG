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
    
    int dailyChallengeNaive(TreeNode* root, int curSum, int targetSum){
        
        if(root == NULL){
            return false;
        }
        if(root->left == NULL and root->right == NULL) return (targetSum == curSum + root->val);
        
        bool left = dailyChallengeNaive(root->left, curSum + root->val, targetSum);
        bool right = dailyChallengeNaive(root->right, curSum + root->val, targetSum);
        
        // cout << "At: " << root->val << ": "<< curSum << endl;
        
        return (left || right);
    }
    
    int dailyChallenge(TreeNode* root, int targetSum){
        
        if(root == NULL) return 0;
        
        
        int left = dailyChallenge(root->left, targetSum - root->val);
        int right = dailyChallenge(root->right, targetSum - root->val);
        
        if(left == INT_MIN and right == INT_MIN) return INT_MIN;
        else if(left == INT_MIN and (right + root->val) == targetSum){
            return targetSum;
        }else if(right == INT_MIN and (left + root->val) == targetSum)
            return targetSum;
        else if(right == left and right == targetSum) return targetSum;
        
        return INT_MIN;
    }
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return dailyChallengeNaive(root, 0, targetSum);
        return (targetSum == dailyChallenge(root, targetSum));
    }
};