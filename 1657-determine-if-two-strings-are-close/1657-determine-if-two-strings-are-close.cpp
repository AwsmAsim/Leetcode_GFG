class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> word2Map, word1Map;
        
        for(char ch: word2) word2Map[ch]++;
        for(char ch: word1) word1Map[ch]++;
        
        unordered_map<int, int> word1Freq, word2Freq;
        
        for(pair<char, int> p: word2Map) ++word2Freq[p.second];
        for(pair<char, int> p: word1Map) ++word1Freq[p.second];
        
        if(word2Freq.size() != word1Freq.size()) return false;
        // cout << "Check 1 Done" << endl;
        
        for(pair<char, int> p: word1Map) if(word2Map.find(p.first) == word2Map.end()) return false;
        
        for(pair<int, int> p: word1Freq){ 
            if(word2Freq.find(p.first) == word2Freq.end()) return false;
            // cout << "Check 2" << endl;
            if(p.second != word2Freq[p.first]) return false;
            // cout << "Check 3" << endl;
        }
        
        return true;
    }
};