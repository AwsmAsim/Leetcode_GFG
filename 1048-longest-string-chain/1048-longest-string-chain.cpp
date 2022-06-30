class Solution {
    
    int lcs(string& a, string& b){
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
        
        for(int i = 1; i < dp.size(); i++){
            for(int j = 1; j < dp[0].size(); j++){
                if(a[i-1] != b[j-1]) dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                else dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
        
        // cout << "\t\tlcs of: " << a << " and " << b << " = " <<  dp[dp.size()-1][dp[0].size()-1] << endl;
        return dp[dp.size()-1][dp[0].size()-1];
    }
    
public:
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), [](const string& s1, const string& s2){
           return s1.size() < s2.size(); 
        });
        
        vector<int> dp(words.size(), 0);
        
        unordered_map<int, int> sizeIndexes; // {sring size: index}
        
        // // string array sorted on the basis of string size
        // for(auto str: words) cout << str<< ", ";
        // cout << endl;
        
        for(int i = 0; i < words.size(); i++){
            if(sizeIndexes.find(words[i].size()) == sizeIndexes.end()){
                sizeIndexes[words[i].size()] = i;
            }
        }
        
        
        for(int i = 0; i < words.size(); i++){
            for(int j = sizeIndexes[words[i].size()-1]; j < i; j++){
                
                if(words[i].size() - words[j].size() != 1) continue;
                
                // cout << words[j].size() << " " << words[i].size() << endl;
                // if(words[j].size() + 1 == words[i].size()){
                    
                    if(lcs(words[j],words[i]) == words[j].size()){
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                // }
            }
            
            // for(auto x: dp) cout << x << ", ";
            // cout << endl;
        }
        
        // // dp 
        // for(auto x: dp) cout << x << ", ";
        // cout << endl;
        
        int maxM = INT_MIN;
        
        for(auto x: dp) maxM = max(maxM, x);
        
        return maxM+1;
    }
};