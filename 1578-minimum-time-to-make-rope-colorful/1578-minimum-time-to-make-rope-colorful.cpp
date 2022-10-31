class Solution {
public:
    
    void _print(vector<vector<int>> list){
        for(vector<int> row: list){
            for(int a: row) cout << a << ", ";
            cout << endl;
        }
    }
    
    int minCost(string colors, vector<int>& neededTime) {
        vector<vector<int>> intervals;
        int n = colors.size();
        bool hadSimilar = false;
        
        for(int i = 0; i < n; i++){
            hadSimilar = false;
            char ch = colors[i];
            int num = neededTime[i];
            vector<int> v = {i, i, num, num};
            while(i < n-1 and colors[i+1] == colors[i]){
                hadSimilar = true;
                v[1] = i + 1;
                v[2] += neededTime[i+1];
                v[3] = max(v[3], neededTime[i+1]);
                ++i;
            }
            if(hadSimilar) --i;
            if(v[0] != v[1]) intervals.push_back(v);
        }
        
        // _print(intervals);
        
        int ans = 0;
        
        for(vector<int> interval: intervals){
            ans += (interval[2] - interval[3]);
        }
        
        return ans;
    }
};