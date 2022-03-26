class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int endInterval, startInterval;
        vector<vector<int>> merged;
        for(int i = 0; i < intervals.size(); i++){
            startInterval = intervals[i][0];
            endInterval = intervals[i][1];
            if(i==intervals.size()-1){
                vector<int> interval = {startInterval, endInterval};
                merged.push_back(interval);
                break;
            }
            while(i<intervals.size()-1 and intervals[i][1] >= intervals[i+1][0]){
                endInterval = max(endInterval, intervals[i+1][1]);
                intervals[i+1][1] = endInterval;
                i++;
            }
            vector<int> interval = {startInterval, endInterval};
            merged.push_back(interval);
        }
        return merged;
    }
};