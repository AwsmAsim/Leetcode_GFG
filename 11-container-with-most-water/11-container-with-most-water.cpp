class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxVal = INT_MIN, width;
        int P1 = 0, P2  = height.size()-1;
        while(P1<P2){
            width = ((P2 - P1));
            maxVal = max(maxVal, width*(min(height[P1], height[P2])) );
            if(height[P1] < height[P2]) P1++;
            else P2--;
        }
        return maxVal;
    }
};