class Solution {
    
    string subStr(string str, int start, int end){
        string s;
        for(int i = start; i < end; i++){
            s.push_back(str[i]);
        }
        return s;
    }
    
public:
    string orderlyQueue(string s, int k) {
        
        if(k>1){
            sort(s.begin(), s.end());
            return s;
        }
        string s1 = s;
        int n = s.size();
        for(int i = 1; i < s.size(); i++){
            // cout << "subStr(" << 0 <<","<<i << "): " << subStr(s,0, i) << endl;
            // cout << (subStr(s,i,n) + subStr(s,0, i)) << endl;
            s1 = min(s1, subStr(s,i,n) + subStr(s,0, i));
        }
        
        return s1;
        
    }
};