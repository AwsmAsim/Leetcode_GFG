class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string wordd1, wordd2;
        
        for(string word: word1) wordd1 += word;
        for(string word: word2) wordd2 += word;
        
        if(wordd1 == wordd2) return true;
        return false;
    }
};