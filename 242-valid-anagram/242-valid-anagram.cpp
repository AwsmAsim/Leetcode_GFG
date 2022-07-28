class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> h1;
        unordered_map<char, int> h2;
        for(char ch: s) ++h1[ch];
        for(char ch: t) ++h2[ch];
        
        for(pair<int, int> p: h1){
            if(h2[p.first] != p.second) return false;
        }
        for(pair<int, int> p: h2){
            if(h1[p.first] != p.second) return false;
        }
        
        return true;
    }
};