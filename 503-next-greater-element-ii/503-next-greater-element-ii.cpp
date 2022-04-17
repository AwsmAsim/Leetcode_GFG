class Solution {
    
    vector<int> NGER(vector<int>& nums){
        vector<int> answer;
        stack<int> s1;
        for(int i = nums.size()*2-1; i>=0; i--){
            while(!s1.empty() and s1.top() <= nums[i%nums.size()]) s1.pop();
            if(i<nums.size())
            if(s1.empty()) answer.push_back(-1);
            else answer.push_back(s1.top());
            s1.push(nums[i%nums.size()]);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
    
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        return NGER(nums);
    }
};