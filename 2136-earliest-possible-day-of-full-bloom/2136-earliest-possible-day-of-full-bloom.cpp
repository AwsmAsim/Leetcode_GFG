class Solution {
public:
    

    static bool comparator(const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second > p2.second;
        }
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
       
        vector< pair<int, int> > list;
        
        int n = plantTime.size();
        
        for(int i = 0; i < n; i++){
            list.push_back(pair<int, int>(plantTime[i], growTime[i]));    
        }
        
        sort(list.begin(), list.end(), comparator);
        
        int start = 0, ans = 0;
        for(int i = 0; i < n; i++){
            start += list[i].first;
            ans = max(ans, start + list[i].second);
        }
        
        return ans;
        
    }
};