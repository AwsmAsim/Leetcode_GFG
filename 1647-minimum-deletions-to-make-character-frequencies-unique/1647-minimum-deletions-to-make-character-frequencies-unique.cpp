class Solution {
public:
    int minDeletions(string s) {
        
        unordered_map<char, int> hMap;
        for(char ch: s) ++hMap[ch];
        
        vector<int> frequencies;
        for(pair<char, int> p: hMap){
            frequencies.push_back(p.second);
        }
        
        sort(frequencies.begin(), frequencies.end(), greater<int>());
        
        int t = INT_MAX, deletions = 0;

        for(int i = 0; i < frequencies.size(); i++){
            if(frequencies[i] >= t){
                deletions += frequencies[i] - max(t-1, 0);
                t = max(t-1, 0);
            }else t = frequencies[i];
        }
        
        return deletions;
    }
};