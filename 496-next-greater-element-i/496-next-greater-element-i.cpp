class Solution {
    
    void print1d(vector<int> v){
        cout << "\n";
        for(auto a: v) cout << a  << " " << endl;
        cout << endl;
    }
    
    vector<int> NGER(vector<int>& nums){
        stack<int> s1;
        vector<int> answer;
        for(int i = nums.size()-1; i >= 0; i--){
            while(s1.size()>0 and s1.top()<nums[i]) s1.pop();
            if(s1.empty()) answer.push_back(-1);
            else answer.push_back(s1.top());
            s1.push(nums[i]);
        }
        reverse(answer.begin(), answer.end());
        // print1d(answer);
        return answer;
    }
    
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hMap;
        vector<int> nger = NGER(nums2);
        for(int i = 0; i < nums2.size(); i++){
            hMap[nums2[i]]  = nger[i];
        }
        for(int i = 0; i < nums1.size(); i++){
            nums1[i] = hMap[nums1[i]];
        }
        return nums1;
    }
};