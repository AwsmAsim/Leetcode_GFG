class Solution {
    
    unordered_set<string> hSet;
    
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morsoCodeFor = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(string word: words){
            string morsoCode = "";
            for(char ch: word){
                morsoCode += morsoCodeFor[ch - 'a'];
            }
            hSet.insert(morsoCode);
        }
        
        return hSet.size();
    }
};