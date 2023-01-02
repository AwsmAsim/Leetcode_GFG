class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1) return true;
        if(word[0] >= 97){
            
            // first alphabet is in lowercase
            
            for(char ch: word){
                if(ch <= 'Z'){
                    return false;
                }
            }
            
        }else{
            
            // first alphabet is in uppercase
            
            if(word[1] >= 'a'){ // second alphabet is lowercase
               for(int i = 1; i < word.size(); i++){
                    char ch = word[i];
                    if(ch <= 'Z'){
                        return false;
                    }
                } 
            }else{ // second alphabet is uppercase
                
                // cout << "Second alphabet is uppercase" << endl;
                
                for(int i = 1; i < word.size(); i++){
                    char ch = word[i];
                    if(ch >= 'a'){
                        return false;
                    }
                }
            }
            
        }
        
        return true;
    }
};