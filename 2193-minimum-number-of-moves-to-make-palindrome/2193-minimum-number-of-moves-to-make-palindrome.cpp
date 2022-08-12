class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int left, n = s.size(), count = 0;
        for(left = 0; left < s.size()/2; left++){
            
            int r = n - left - 1;
            // cout << "left: " << s[left] << " " << " right: " << s[r] << endl;
            
            while(s[left] != s[r]){
                --r;
            }
            if(r != left){
                for(int k = r; k < n - left -1; k++){
                    // cout << "swapping " << s[k] << " with " << s[k+1] << endl;
                    swap(s[k], s[k+1]);
                    ++count;
                }
            }else{
                
                    // cout << "Exceptional swap: " << s[left] << " with " << s[left + 1] << endl;
                swap(s[left], s[left + 1]);
                ++count;
                --left;
            }
        }
        
        return count;
    }
};