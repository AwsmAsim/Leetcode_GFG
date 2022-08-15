class Solution {
    
    unordered_map<char, int> rtoi = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    }; // Roman to integer hash map
    
    int dailyChallenge(string s){
        vector<int> intValues(s.size(), 0);
        for(int i = 0; i < s.size(); i++){
            intValues[i] = rtoi[s[i]];
        } 
        
        for(int i = 0; i < intValues.size()-1; i++){
            if(intValues[i] < intValues[i+1]){
                intValues[i+1] -= intValues[i];
                intValues[i] = 0;
                ++i;
            }
        }
        
        // for(int num: intValues) cout << num << ", ";
        // cout << endl;
        
        int ans = 0;
        for(int i = 0; i < s.size(); i++) ans+=intValues[i];
        
        return ans;
    }
    
public:
    int romanToInt(string s) {
        return dailyChallenge(s);
    }
};