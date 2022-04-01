class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), wStart = 0, wEnd = n - k - 1, maxScore = INT_MIN, outSum;
        vector<int> prefSum(n);
        prefSum[0] = cardPoints[0];
        for(int i = 1; i < n; i++) prefSum[i] = cardPoints[i] + prefSum[i-1];
        
        // cout << "prefSum" << endl;
        // for(auto a: prefSum) cout << a << " ";
        
        if(wEnd<0) return prefSum[n-1];
        while(wEnd < n){
            // cout << "wStart: " << wStart << " wEnd: " << wEnd << endl;
            if(wStart == 0) maxScore = max(maxScore, prefSum[n-1]-prefSum[wEnd]);
            else if(wEnd != n-1){
                // if(wEnd != wStart)
                outSum = prefSum[wEnd] - prefSum[wStart-1];
                // cout << "prefSum[n-1]: " << prefSum[n-1] << " outSum " << outSum << endl;
                maxScore = max(maxScore, prefSum[n-1]-outSum);
            }else{
                maxScore = max(maxScore, prefSum[wStart-1]);
            }
            // cout << " maxScore: " << maxScore << endl;
            ++wStart;
            ++wEnd;
        }
        
        return maxScore;
    }
};