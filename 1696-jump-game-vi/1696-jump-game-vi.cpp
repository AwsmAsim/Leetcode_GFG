class Solution {
    
    struct comparator{
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.first < p2.first;
        }
    };
    
    int recursive(vector<int>& nums, int& k, int idx){
        
        if(idx >= nums.size()) return -100001;
        if(idx == nums.size()-1) return nums[idx];
        
        int maxP = INT_MIN, points;
        for(int i = 1; i <= k; ++i){
            points = nums[idx] + recursive(nums, k, idx + i);
            maxP = max(maxP, points);
        }
        
        
        return maxP;
    }
    
    int bottomUp(vector<int>& nums, int& k, int idx){
        
        vector<int> dp(nums.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq; // <int, int> = <value , idx>
        
        dp[0] = nums[0];
        pq.push({dp[0], 0});
        for(int i = 1; i < nums.size(); i++){
            // if(i-k >= 0){
                // int tMax = INT_MIN;
                // for(int j = i - k; j < i; j++){
                //     // cout << j <<" ";
                //     tMax = max(dp[j], tMax);
                // }
                while(pq.top().second < i-k) pq.pop();
                int tMax = pq.top().first;
                // pq.pop();
                // cout << endl;
                // cout << "\t tMax: " << tMax << " " << nums[i] << " + " << tMax << endl;
                dp[i] = nums[i] + tMax;
                pq.push({dp[i], i});
            // }
        // else{
        //         // int tMax = INT_MIN;
        //         // for(int j = 0; j < i; j++){
        //         //     // cout << j <<" ";
        //         //     tMax = max(dp[j], tMax);
        //         // }
        //         int tMax = pq.top().first;
        //         // pq.pop();
        //         dp[i] = max(nums[i], nums[i]+tMax);   
        //         pq.push({dp[i], i});
        //     }
        }
        
        //print dp
        // for(int value: dp) cout << value << ", ";
        // cout << endl;
        // if(dp[dp.size()-1] < 0) return 0;
        return dp[nums.size()-1];
        
    }
    
public:
    int maxResult(vector<int>& nums, int k) {
        return bottomUp(nums, k, 0);
        return recursive(nums, k, 0);
    }
};