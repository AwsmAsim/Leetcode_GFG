class Solution {
    
    void solve(int idx, int n, vector<char>& temp, vector<char>& vowels, int& count){
        
        if(temp.size() >= n or idx == vowels.size()){
            // ++count;
            // temp.pop_back();
            // for(auto a: temp) cout << a << ", ";
            // cout << endl;
            ++count;
            return;
        }
        if(idx == vowels.size()) return;
        for(int i = idx; i < vowels.size() ;i++){
            temp.push_back(vowels[i]);
            solve(i, n, temp, vowels, count);
            temp.pop_back();
        }
        
    }
    
public:
    int countVowelStrings(int n) {
        vector<char> temp;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int count = 0;
        solve(0, n, temp, vowels, count);
        return count;
    }
};