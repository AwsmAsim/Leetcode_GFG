class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> s1;
        vector<int> maxV;
        for(int i = prices.size()-1; i >= 0; i--){
            while(s1.size()>0 and s1.top()<prices[i]) s1.pop();
            if(s1.empty()){
                s1.push(prices[i]);
                maxV.push_back(0);
            } 
            else {
                // cout << s1.top() << " - " << prices[i] << " = " << s1.top()-prices[i] << endl;
                maxV.push_back(s1.top()-prices[i]);
            }
        }
        int maxP = INT_MIN;
        for(auto a: maxV) maxP = max(a, maxP);
        if(maxP < 0) return 0;
        return maxP;
    }
};