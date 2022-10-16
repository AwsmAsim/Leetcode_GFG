class Solution {
    
    void _print2d(vector< vector<int> > arr){
        for(vector<int> row: arr){
            for(int num: row) cout << num << ", ";
            cout << endl;
        }
        cout << endl;
    }
    
    int solve(int idx, int days, vector<int>& jobDifficulty, vector<vector<int>>& maxArr, vector<vector<int>>& dp){
        
        // cout << idx << " " << days << endl;
        if(idx == jobDifficulty.size()){
            return INT_MAX;
        }
        if(days == 1){
            return maxArr[idx][jobDifficulty.size()-1];
        }
        if(dp[idx][days] != -1) return dp[idx][days];
        
        
        int answer = INT_MAX;
        for(int i = idx; i < jobDifficulty.size(); ++i){
            int curMax = maxArr[idx][i];
            int pick = solve(i + 1, days - 1, jobDifficulty, maxArr, dp);
            // cout << "for " << idx << " " << i << " cMax = " << curMax << " pick: " << pick << endl;
            if(pick == INT_MAX) continue;
            
            answer = min(answer, pick + curMax);
            // cout << "for " << idx << " " << i << " answer = " << answer << endl;
        }
        
        return dp[idx][days] = answer;
    }
    
    
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size()) return -1;
        vector<vector<int>> maxArr(jobDifficulty.size(), vector<int>(jobDifficulty.size(), 0));
        vector<vector<int>> dp(10001, vector<int>(11, -1));
        
        for(int i = 0; i < jobDifficulty.size(); i++){
            int curMax = jobDifficulty[i];
            for(int j = i; j < jobDifficulty.size(); j++){
                if(curMax < jobDifficulty[j]){
                    curMax = jobDifficulty[j];
                }
                maxArr[i][j] = curMax;
            }
        }
        
        // _print2d(maxArr);
        
        int answer = solve(0, d, jobDifficulty, maxArr, dp);
        if(answer == INT_MAX) return -1;
        return answer;
        
    }
};