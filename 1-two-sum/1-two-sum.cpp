class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indicies;
        vector<int> answer;
        int secondElement, a, i;
        for(i = 0; i < nums.size(); i++){
            indicies[nums[i]] = i+1;
        }
        for(i=0; i < nums.size(); i++){
            a = nums[i];
            secondElement = target - a;
            if(indicies[secondElement] > 0 and indicies[secondElement]-1 != i){
                answer.push_back(i);
                answer.push_back(indicies[secondElement]-1);
                return answer;
            }
        }
        return answer;
    }
};