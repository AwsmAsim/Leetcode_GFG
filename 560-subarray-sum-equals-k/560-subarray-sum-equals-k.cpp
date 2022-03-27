class Solution {
    
    void printList(vector<int> lst){
        for(auto a: lst) cout << a <<" ";
        cout << endl;
    }
    
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefSum(nums.size(), 0);
        unordered_map<int, int> hMap;
        prefSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) prefSum[i] = prefSum[i-1] + nums[i];
        // printList(prefSum);
        int count = 0;
        for(int i = 0; i < nums.size(); i++) if(prefSum[i] == k) count++;
        for(int i = 0; i < prefSum.size(); i++){
            if(hMap[prefSum[i] - k] != 0){
                count += hMap[prefSum[i] - k];
            }
            hMap[prefSum[i]]++;
        }
        
        return count;
    }
};