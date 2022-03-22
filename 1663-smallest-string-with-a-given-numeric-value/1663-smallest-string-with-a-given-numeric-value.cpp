class Solution {
public:
    string getSmallestString(int n, int k) {
        string answer;
        
        for(int i = 0; i < n; i++) answer.push_back('z');
        for(int i = n-1; i >= 0; i--){
            if((k-i)>=26){
                answer[i] = 'z';
                k-=26;
            }else{
                answer[i] = (char) (96+k-i);
                k=i;
            }
        }
        
        return answer;
    }
};