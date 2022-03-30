class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> hMap;
        int left, count = 0;
        // for(int i = 0; i < time.size(); i++){
        //     hMap[time[i]%60]++;
        // }
        
        for(int i = 0; i < time.size(); i++){
            left = time[i]%60;
            // cout << "left: " << left << endl;
            if(left==0) count += hMap[0]++;
            else{
                count += hMap[60-left];
                hMap[left]++;
            }
            // cout << time[i] << endl;
        }
        // cout << endl;
        
        return count;
    }
};