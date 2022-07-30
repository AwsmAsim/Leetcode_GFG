class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> word_map2, word_map;
        
        for(string str: words2){
            unordered_map<char,int> t_map;
            for(char ch: str){
                t_map[ch]++;
                word_map2[ch] = max(word_map2[ch], t_map[ch]);
            }
        }
        
        // for(auto p: word_map2){
        //          cout << p.first << ": " << p.second << ",  ";
        //     }
        //     cout << endl;
        
        vector<string> v;
        
        for(string str: words1){
            unordered_map<char, int> m1;
            for(char ch: str){
                m1[ch]++;
            }
            int flag = 1;
            
            // for(auto p: m1){
            //      cout << p.first << ": " << p.second << ",  ";
            // }
            // cout << endl;
            
            for(pair<char, int> p: word_map2){
                if(p.second > m1[p.first]){
                    // cout << p.first << " is not same because " << "word_map2["<<  p.first<<"] = " << p.second << " and m1[" << p.first << "] = " << m1[p.first] <<endl ;
                    flag = 0;
                    break;
                }
            }
            
            if(flag){
                v.push_back(str);
            }
        }
        
        return v;
        
    }
};