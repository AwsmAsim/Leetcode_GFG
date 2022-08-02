class Solution {
    
    set<vector<int>> answerSet;
    
    void printList(vector<int> v){
        for(int a: v) cout << a << ", ";
        cout << endl;
    }
    
    int recursive(int idx, int prev_idx, vector<int>& v, vector<int>& nums){
        
        // cout << idx << " " << prev_idx << endl;
        // printList(v);
        
        if(idx >= nums.size()){
            return 0;
        }
        int pick = INT_MIN;
        if(prev_idx == -1 or nums[idx] >= nums[prev_idx]){
            v.push_back(nums[idx]);
            if(v.size() >= 2) answerSet.insert(v);
            pick = 1 + recursive(idx + 1, idx, v, nums);
            if(v.size() >= 1) v.pop_back();
        }
        
        int notPick = recursive(idx + 1, prev_idx, v, nums);
        
        
        return max(pick, notPick);
    }
    
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        recursive(0, -1, v, nums);
        vector<vector<int>> answer;
        for(vector<int> v: answerSet){
            answer.push_back(v);
        }
        return answer;
    }
};