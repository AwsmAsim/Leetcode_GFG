class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());
        int balloons = 1;
        int start = points[0][0], end = points[0][1];
        
        for(int i = 1; i < points.size(); i++){
            
            int currentStart = points[i][0];
            int currentEnd = points[i][1];
            
            cout << currentStart << " " << currentEnd << ": ";
            if(currentStart >= start and currentStart <= end){
                // It falls in the interval
                start = max(start, currentStart);
                end = min(end, currentEnd);
                
                // cout << " Merges --> " << start << ", " << end << endl;
            }else{
                start = currentStart;
                end = currentEnd;
                ++balloons;
                
                // cout << "New Interval " << start << ", " << end  << endl;
            }
        }    
        
        return balloons;
    }
};