class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.size() > s.size()) return "";
        
        unordered_map<char, int> original, curCount;
        int wStart = 0, wEnd = 0, wSize, ansStart = -1, ansEnd = -1, mScore = 0, minW = INT_MAX;
        
        for(char ch: t) ++original[ch];
        
        
        for(wStart = 0; wStart < s.size(); ++wStart){
            if(original[s[wStart]]) break;
        }
        
        wEnd = wStart;
        
        for(; wEnd < s.size(); ++wEnd){
            // cout << wEnd << endl;
            char ch = s[wEnd];
            if(original[ch]){
                ++curCount[ch];
                if(curCount[ch] <= original[ch]){
                    ++mScore;
                }
            }
            if(mScore == t.size()){
                
                while(mScore == t.size()){
                    wSize = wEnd - wStart + 1;
                // cout <<  ": wStart: " << wStart << " wEnd: " << wEnd << "wSize: " << wSize << endl;
                    if(wSize < minW){
                        // cout << "wSize changed" << endl;
                        minW = wSize;
                        ansStart = wStart, ansEnd = wEnd;
                    }
                    if(original[s[wStart]] and curCount[s[wStart]] <= original[s[wStart]]){
                        --mScore;
                    }
                    if(original[s[wStart]]) --curCount[s[wStart]];
                    ++wStart;
                }
            }
        }
        
        // cout << "ansStart: " << ansStart << " ansEnd: " << ansEnd << endl;
        
        if(ansStart == -1) return "";
        string answer;
        for(int i = ansStart; i <= ansEnd; ++i){
            answer.push_back(s[i]);
        }
        
        return answer;
        
    }
};