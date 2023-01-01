class Solution {
    
    void sentenceToStringList(string sentence, vector<string>& words){
        string s;
        for(char ch: sentence){
            if(ch == ' ' ){
                words.push_back(s);
                s = "";
            }else{
                s.push_back(ch);
            }
        }
        words.push_back(s);
    }
    
public:
    bool wordPattern(string pattern, string s) {
        
        // If there are more than 26 distinct words, then return false; (sizeOf(map) > 26)
        char chCounter = 'a';
        unordered_set<char> used;
        unordered_map<string, char> wordToChar;
        vector<string> words;
        
        sentenceToStringList(s, words); // "Hello World" --> ["Hello", "World"]
        
        if(words.size() != pattern.size()) return false;
        
        for(int i = 0; i < pattern.size(); i++){
            string str = words[i];
            if(wordToChar.find(str) == wordToChar.end()){
                // There is no registry for this word
                if(wordToChar.size() > 26) return false;
                
                // The word has occured the first time, but now we need to evaluate the pattern character
                if(used.find(pattern[i]) != used.end()) return false;
                
                wordToChar[str] = pattern[i];
                used.insert(pattern[i]);
            }else{
                char currentChar = pattern[i];
                char registeredChar = wordToChar[str];
                // The character that occured now for the corresponding word should be same as the character earlier.
                
                if(currentChar != registeredChar) return false;
            }
        }

        
        return true;
        
    }
};
























