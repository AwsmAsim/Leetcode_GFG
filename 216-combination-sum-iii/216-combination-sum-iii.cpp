class Solution {
    
    
    void getCombinations(vector<int>& nums, int k, vector<vector<int>>& answer, int idx, int leftSum, vector<int>& c_ans){
        
        // cout << "(" << idx << ", " << leftSum << ", {";
        // for(auto a: c_ans) cout << a << ", ";
        // cout << "} }" << endl;
        
        if(c_ans.size() == k){
            if(leftSum == 0) answer.push_back(c_ans);
            leftSum += c_ans[c_ans.size()-1];
            // c_ans.pop_back();
            return;
        }
        if(idx >= nums.size()){
            return;
        }
        
        // pick
        c_ans.push_back(nums[idx]);
        getCombinations(nums, k, answer, idx + 1, leftSum - nums[idx], c_ans);
        // c_ans.pop_back();
        
        //non-pick
        c_ans.pop_back();
        getCombinations(nums, k, answer, idx + 1, leftSum, c_ans);
        
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> answer;
        vector<int> c_ans;
        getCombinations(nums, k, answer, 0, n, c_ans);
        return answer;
        
    }
};