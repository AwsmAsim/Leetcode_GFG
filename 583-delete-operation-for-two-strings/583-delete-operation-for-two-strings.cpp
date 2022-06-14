class Solution {
    
    void printDp(vector<vector<int>> dp){
        for(auto row: dp){
            for(auto element: row) cout << element << ", ";
            cout << endl;
        }
    }
    
    int lcsMemo(string word1, string word2){
        int count = 0;
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        
        for(int i = 1; i <= word1.size(); ++i){
            for(int j = 1; j <= word2.size(); ++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // printDp(dp);
        
        int delFromWord1 = word1.size() - dp[dp.size()-1][dp[0].size()-1];
        int insertInWord2 = word2.size() - dp[dp.size()-1][dp[0].size()-1];
        
        return (delFromWord1 + insertInWord2);
    }
    
public:
    int minDistance(string word1, string word2) {
        return lcsMemo(word1, word2);
    }
};