class Solution {
public:

    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long long width1 = abs(ax1 - ax2), height1 = abs(ay1 - ay2);
        long long width2 = abs(bx1 - bx2), height2 = abs(by1 - by2);
        
        long long area1 = height1 * width1;
        long long area2 = height2 * width2;
        
        int cx1 = max(ax1, bx1), cy1 = max(ay1, by1), cx2 = min(ax2, bx2), cy2 = min(ay2, by2);
        long long width3 = cx2 - cx1, height3 = cy2 - cy1;
        long long area3 = height3 * width3;
        
        if(width3 < 0 or height3 < 0) return (int)(area1 + area2);
        else return (int)(area1 + area2 - area3);
        return -1;
        
    }
};