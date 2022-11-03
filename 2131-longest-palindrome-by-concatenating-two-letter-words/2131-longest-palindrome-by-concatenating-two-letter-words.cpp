class Solution {
    
    void _print(unordered_map<string, int>& hMap){
        
        for(pair<string, int> p: hMap){
            cout << p.first << " " << p.second << ", ";
        }
        cout << endl;
        
    }
    
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string, int> freqMap;
        vector<string> sameLetterWords;
        int size = 0;
        int sameLetterWordsCount = 0;
        
        for(string word: words){
            freqMap[word]++;
        }
        // _print(freqMap);
        
        for(string word: words){
            if(freqMap[word] < 1) continue;
            string inverse = word;
            reverse(inverse.begin(), inverse.end());
            if(inverse == word){
                
                sameLetterWords.push_back(word);
                
                continue;
            }
            if(freqMap[inverse] >= 1){
                // cout << word  << "  " << inverse << endl;
                size += 4;
                --freqMap[inverse];
                --freqMap[word];
            }
        }
        
        for(string word: sameLetterWords){
            if(freqMap[word] == 0) continue;
            if(freqMap[word]&1) ++sameLetterWordsCount;
            // cout << word << " freq: " << freqMap[word] << " " << (freqMap[word] / 2) << endl;
            size += ((freqMap[word] / 2)*4);
            freqMap[word] = 0;
        }
        
        if(sameLetterWordsCount > 0) size += 2;
        
        return size;
        
    }
};