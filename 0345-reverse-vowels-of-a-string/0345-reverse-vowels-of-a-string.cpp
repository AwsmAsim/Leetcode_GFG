class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();        
        int start = 0, end = n-1;
        unordered_set<int> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        while(start < end){
            while(start < end and vowels.find(s[start]) == vowels.end()){
                ++start;
            } 
            while(end > start and vowels.find(s[end]) == vowels.end()){
                --end;
            }
            swap(s[start], s[end]);
            ++start;
            --end;
        }
        
        return s;
        
    }
};