class Solution {
    
    string subStr(string str, int begin){
        string str1;
        for(int i = begin; i < str.size(); i++){
            str1.push_back(str[i]);
        }
        
        return str1;
    }
    
    
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        unordered_map<string, int> trieMap;
        unordered_map<string, int> wordFreq;
        int answer = 0;
        
        // Making the wordFreq
        for(auto word: words){
            wordFreq[word]++;
        }
        
        // Making the trie Map
        for(auto word: words){
            string newWord;
            
            for(int i = 0; i < word.size(); i++){
                newWord = subStr(word, i);
                trieMap[newWord]++;
            }
        }
        
        // // Print trieMap
        // for(auto trieData: trieMap){
        //     cout << trieData.first << ": " << trieData.second << ", ";
        // }
        // cout << endl;
        
        // // Print wordFreq
        // for(auto wordData: wordFreq){
        //     cout << wordData.first << ": " << wordData.second << ", ";
        // }
        // cout << endl;
        
        for(string word: words){
            if(trieMap[word] == 1){
                answer += (word.size() + 1);
            }else if(wordFreq[word]>1 and trieMap[word] == wordFreq[word]){
                answer += (word.size() + 1);
                wordFreq[word] = 0;
            }
        }
        
        return answer;
        
    }
};