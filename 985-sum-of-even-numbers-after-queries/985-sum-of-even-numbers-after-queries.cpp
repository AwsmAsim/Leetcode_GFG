class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum1 = 0;
        vector<int> answer;
        for(int num: nums) 
            if((num&1) == 0)
            sum1 += num;
        
        for(int i = 0; i < queries.size(); i++){
            int idx = queries[i][1], val = queries[i][0];
            if(((nums[idx]&1) and (val&1))){
                sum1 += (val + nums[idx]);
            }
            if((nums[idx]&1)==0 and (val&1)==0){
                sum1 += val;
            }
            else{
                if((nums[idx]&1)==0) sum1 -= nums[idx];
            }
            answer.push_back(sum1);
            nums[idx] += val;
        }
        
        
        return answer;
    }
};