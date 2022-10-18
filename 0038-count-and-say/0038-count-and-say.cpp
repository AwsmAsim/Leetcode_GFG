class Solution {
    
    
    string recur(string num, int count, int limit){
        
        if(count == 0){
            return recur("1",1,limit);
        }
        
        if(count == limit) return num;
        
        
        vector<pair<char, char>> say;
        int curFreq = 0;
        char curNum = num[0];
        
        for(int i = 0; i < num.size(); ++i){
            if(num[i] == curNum){
                ++curFreq;
            }else{
                // cout << (curFreq ) << " ";
                say.push_back(pair<char, char>(curFreq + '0', curNum));
                curNum = num[i];
                curFreq = 1;
            }
        }
        say.push_back(pair<char, char>((curFreq + '0'), curNum));
        // cout << say[0].first <<  " " << say[0].second << endl; 
        
        string ans = "";
        
        for(int i = 0; i < say.size(); i++){
            ans.push_back(say[i].first);
            ans.push_back(say[i].second);
        }
        
        return recur(ans, count + 1, limit);
        
        
    }
    
    
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        return recur("", 0, n);
    }
};