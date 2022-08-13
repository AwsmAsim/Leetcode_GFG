class Solution {
    
    bool isValid(int wStart, int wSize, string& s, unordered_map<string, int>& hMap, int wordSize){
        unordered_map<string, int> hMap1 = hMap;
        for(int i = wStart; i < wStart + wSize; i+=wordSize){
            string word = s.substr(i, wordSize);
            // cout << word << endl;
            // cout << hMap1.size() << endl;
            if(hMap.find(word) == hMap.end()) return false;
            --hMap1[word];
            if(hMap1[word] == 0) hMap1.erase(word);
        }
        // cout << "hMap1 size: " << hMap1.size() << " hMap size: " << hMap.size() << endl;
        if(hMap1.size()==0) return true;
        return false;
    }
    
    // int startIdx = (i+wSize) - (wordSet.size()*wSize);
    
    vector<int> dailyChallenge(string& s, vector<string>& words){
        unordered_map<string, int> hMap;
        vector<int> answer;
        for(string word: words) ++hMap[word];
        
        int wSize = words.size() * words[0].size(), wStart = 0, wEnd = wSize - 1, wordSize = words[0].size();
        if(wEnd >= s.size()) return {};
        
        while(wEnd < s.size()){
            // cout << "wEnd: " << wEnd << " wStart: " << wStart << endl;
            if(isValid(wStart, wSize, s, hMap, wordSize)){
                answer.push_back(wStart);
            }
            ++wEnd, ++wStart;
            // wEnd += words[0].size(), wStart += words[0].size();
        }
        
        return answer;
    }
    
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        return dailyChallenge(s, words);
    }
};