class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod = 1000000007;
        horizontalCuts.push_back(0); horizontalCuts.push_back(h%mod);
        verticalCuts.push_back(0); verticalCuts.push_back(w%mod);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxH, maxW, currH, currW;
        
        for(int i = 1; i < horizontalCuts.size(); i++){
            currH = horizontalCuts[i]%mod - horizontalCuts[i-1]%mod;
            maxH = max(currH, maxH);
        }
        
        for(int i = 1; i < verticalCuts.size(); i++){
            currW = verticalCuts[i]%mod - verticalCuts[i-1]%mod;
            maxW = max(currW, maxW);
        }

        int ans = ((long long)(maxH%mod)*(maxW%mod)%mod);
        
        return ans;
    }
};