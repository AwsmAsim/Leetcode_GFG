class Solution {
public:
    
    int noOfVowels(int startIdx, int endIdx, string& s){
        int count = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i = startIdx; i < endIdx; i++){
            if(vowels.find(s[i]) != vowels.end()) ++count;
        }
        return count;
    }
    
    bool halvesAreAlike(string s) {
        return noOfVowels(0, s.size()/2, s) == noOfVowels(s.size()/2, s.size(), s);
    }
};