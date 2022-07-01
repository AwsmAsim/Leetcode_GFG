class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[1]>v2[1];
        });
        
        int leftOver = truckSize, cIdx = 0, answer = 0;
        
        while(leftOver > 0){
            if(boxTypes[cIdx][0] < leftOver){
                leftOver -= boxTypes[cIdx][0];
                answer += (boxTypes[cIdx][1]*boxTypes[cIdx][0]);
                ++cIdx;
                if(cIdx >= boxTypes.size()) break;
            }else{
                int required = leftOver;
                answer += (boxTypes[cIdx][1]*leftOver);
                leftOver = 0;
                break;
            }
        }
        
        return answer;
    }
};