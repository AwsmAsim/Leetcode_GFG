class Solution {
    
    void printList2d(vector<vector<int>> list){
        for(auto row: list){
            for(auto a: row) cout << a<< " ";
            cout << endl;
        }
    }
    
    // void checkDuplicates(vector<vector<int>> answer, vector<int> answer;)
    
    void getCombinations(int idx, int target, vector<int> v, vector<vector<int>>& answer, vector<int>& candidates){
        if(idx == candidates.size()){
            if(target == 0) answer.push_back(v);
            // printList2d(answer);
            return;
        }  
        
        getCombinations(idx+1, target, v, answer, candidates);
        if(candidates[idx] <= target){
            v.push_back(candidates[idx]);
            getCombinations(idx, target - candidates[idx], v, answer, candidates);
        }
        // else getCombinations(idx+1, target, v, answer, candidates);
            
        
        
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> v;
        getCombinations(0, target, v, answer, candidates);
        return answer;
    }
};