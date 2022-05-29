class Solution {
    
    int max(int num1, int num2){
        if(num1 > num2) return num1;
        else return num2;
    }
    
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> fL;
        int maxProduct = -1;
        
        for(int i = 0; i < words.size(); i++){
            unordered_map<int,int> fL;
            for(auto ch: words[i]){
                fL[ch]++;
            }
            // cout << "currently: " << words[i] << endl;
            for(int j = i+1; j < words.size(); ++j){
                int curMax = words[i].size()*words[j].size();
                for(auto ch:  words[j]){
                    if(fL.find(ch)!=fL.end()){
                        curMax = -1;
                        break;   
                    }   
                }
                // cout << "\t" << words[j] << " curMax: " << curMax << endl;
                maxProduct = max(maxProduct, curMax);
            }
        }
        if(maxProduct == -1) return 0;
        return maxProduct;
    }
};