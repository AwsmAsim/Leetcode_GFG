class Solution {
    
    int getSum(int start, int end, vector<int>& prefSum){
        
        // cout << start << " " << end << endl;
        if(start == 0) return prefSum[end];
        return (prefSum[end] - prefSum[start -1]);
        
    }
    
    int min(long long a, long long b){
        if(a < b) return a;
        else return b;
    }
    
    int naturalNoSum(int n){
        return ((long long)n*(n+1)/2);
    }
    
    void _print(vector<int> nums){
        for(int num: nums){
            cout << num << " ,";
        }
        cout << endl;
    }
    
public:
    int minMoves(vector<int>& nums, int k) {
        
        vector<int> idxes;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]) idxes.push_back(i);
        }
        
        int start = 0, end = k-1;
        
        vector<long long> prefSum(idxes.size(), 0);
        prefSum[0] = idxes[0];
        
        for(int i = 1; i < prefSum.size(); i++){
            prefSum[i] = prefSum[i-1] + idxes[i];
        }
        
        // _print(idxes);
        // _print(prefSum);
        
        int minAns = INT_MAX;

        for(; end < idxes.size(); ++end, ++start){
            long long mid = start+(k+1)/2-1;
            // cout << "mid: " << mid;
            long long leftSum = (mid==0?0:prefSum[mid-1])-(start==0?0:prefSum[start-1]);
            long long rightSum = prefSum[end]-prefSum[mid];
            // cout << "leftSum:" << leftSum << " rightSum: " << rightSum << endl;
            long long rad = mid - start;
            long long save = rad*(rad+1);
            long long ans = rightSum - leftSum - save;
            if(k%2==0){
                save += (rad+1);
                ans = (rightSum - idxes[mid] - leftSum - save);
            }
            minAns = min(minAns, ans);
        }
        
        return minAns;
        
    }
};