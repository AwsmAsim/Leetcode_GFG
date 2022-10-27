class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        map<pair<int, int>, int> pairScore;
        vector<pair<int, int>> img1Idxes, img2Idxes;
        int n = img1.size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j]) img1Idxes.push_back(pair<int, int>(i, j));
                if(img2[i][j]) img2Idxes.push_back(pair<int, int>(i, j));
            }
        }
        
        int maxScore = 0;
        
        for(pair<int, int> p1: img1Idxes){
            for(pair<int, int> p2: img2Idxes){
                pair<int, int> p = pair<int, int>(p1.first - p2.first, p1.second - p2.second);
                pairScore[p]++;
                maxScore = max(maxScore, pairScore[p]);
            }
        }
        
        return maxScore;
        
    }
};