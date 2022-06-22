class Solution {
    
    int withPQ(vector<int>& nums, int k){
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        for(; i < k; i++){
            pq.push(nums[i]);
        }
        
        for(i = k; i < nums.size(); ++i){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        return pq.top();
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        return withPQ(nums, k);
    }
};