class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        multiset<char> letterSet;
        
        for(char ch: magazine) letterSet.insert(ch);
        
        for(char ch: ransomNote){
            if(letterSet.find(ch) == letterSet.end()) return false;
            letterSet.erase(letterSet.find(ch));
        }
        
        return true;
        
    }
};