class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==1) return 1;
        vector<int> left(ratings.size(), 1), right(ratings.size(), 1);
        int sum1 = 0;
        
        // if(max(ratings[0], ratings[1]) == ratings[0]) left[]
        for(int i = 1 ;i < ratings.size(); i++){
            if(max(ratings[i-1], ratings[i]) == ratings[i] and ratings[i-1]!=ratings[i]) left[i] =left[i-1] + 1;
        }
        
        // for(auto a: left) cout << a << ", ";
        // cout << endl;
        
        for(int i = ratings.size()-2; i >= 0; i--){
            if(max(ratings[i], ratings[i+1]) == ratings[i] and ratings[i+1]!=ratings[i]) right[i] = right[i+1] + 1;
        }
        
        // for(auto a: right) cout << a << ", ";
        // cout << endl;
        
        for(int i = 0; i < ratings.size(); i++){
            sum1 += max(left[i], right[i]);
        }
        
        return sum1;
    }
};