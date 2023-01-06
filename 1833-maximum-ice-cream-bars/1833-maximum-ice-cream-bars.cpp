class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count = 0, total = 0;
        sort(costs.begin(), costs.end());
        for(int i = 0; i < costs.size(); i++){
            total += costs[i];
            if(total > coins) break;
            ++count;
        }
        return count;
    }
};