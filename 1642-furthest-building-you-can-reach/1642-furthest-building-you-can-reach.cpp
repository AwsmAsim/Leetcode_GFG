class Solution {
public:
    int furthestBuilding(vector<int>& hs, int brks, int ldrs) {
        int n = hs.size();
        priority_queue<int> pq;

        for(int i=0; i<n-1; i++)
        {
            if(hs[i+1] > hs[i]) {
                int gap = hs[i+1] - hs[i];
                brks -= gap;
                pq.emplace(gap);

                if(brks < 0) {
                    if(ldrs--) {
                        brks += pq.top();
                        pq.pop();
                    }
                    else return i;
                }
            }
        }

        return n-1;
    }
};