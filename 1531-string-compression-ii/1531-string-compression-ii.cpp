int dp[101][27][101][101];
class Solution {
public:
    string str;
    int solve(int i, char prev, int cLen, int k,string& s){
        if(k < 0) return INT_MAX;
        if(i >= s.size()) return 0;
        // cout << i << " " << (prev - '`') << " " << cLen << " " << k << " " << endl;
        if(dp[i][prev - '`'][cLen][k] != -1) return dp[i][prev - '`'][cLen][k];
        
        int notPick = solve(i + 1, prev, cLen, k-1, s);
        int pick = INT_MAX;
        
        int keep = 0;
        if(prev == s[i]){
            if(cLen == 1 || cLen == 9 || cLen == 99) keep += 1;
            pick = keep + solve(i+1, s[i], cLen + 1, k, s); 
        }else{
            pick = 1 + solve(i+1, s[i], 1, k, s);
        }
        
        
        return dp[i][prev - '`'][cLen][k] = min(pick, notPick);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, '`', 0, k, s);
    }
};