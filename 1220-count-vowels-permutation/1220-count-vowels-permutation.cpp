class Solution {
    
    int mod = 1000000007;
    unordered_map<char, unordered_set<char>> allowedCharacters = {
        {'a', {'e'}}, {'e', {'a', 'i'}}, {'i', {'a','e','o','u'}}, {'o',{'i','u'}}, {'u',{'a'}}
    };
    
    long long countWords(char ch, int n, vector<vector<long long>>& dp){
        if(n==0) return 1;
        if(dp[ch-97][n] != -1) return dp[ch-97][n];
        long long count = 0;
        for(char ch1: allowedCharacters[ch]){
            count = (count%(mod) + countWords(ch1, n-1, dp))%(mod);
        }
        
        dp[ch-97][n] = count;
        return dp[ch-97][n];
    }
    
public:
    int countVowelPermutation(int n) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<vector<long long>> dp(26, vector<long long>(n, -1));
        long long count = 0;
        for(char ch: vowels){
            count = ((count)%mod + (countWords(ch, n-1, dp)%mod))%mod;
        }
        return (count)%((int)1e9+7);
    }
};