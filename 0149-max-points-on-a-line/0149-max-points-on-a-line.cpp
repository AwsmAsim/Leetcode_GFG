class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int ans = 0;
        unordered_map<float, int>mp;
        
        for(int i = 0 ; i < points.size(); i++)
        {
              for(int j = i+1 ; j < points.size(); j++)
              {
                  float y2 = points[j][1], y1 = points[i][1];
                  float x2 = points[j][0], x1 = points[i][0];
                  float slope = (y2-y1)/(x2-x1);
                    if( (y2-y1) < 0 && (x2-x1) == 0) //infinite slope
                         mp[abs(slope)]++;
                    else
                        mp[slope]++;
              }
            for(auto e : mp)
            {
               int temp = e.second;
               ans = max(ans, temp);
            }
        mp.clear();
        }
           
        return ans+1;    
    }
};