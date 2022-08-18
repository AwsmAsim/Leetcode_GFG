class Solution {

    
    void printList(vector<int> v){
        for(int a: v) cout << a << ", ";
        cout << endl;
    }
    
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int, int> hMap;
        for(int num: arr){
            ++hMap[num];
        }
        vector<int> freq;
        for(pair<int, int> p: hMap){
            freq.push_back(p.second);
        }
        sort(freq.begin(), freq.end());
        // printList(freq);
        int half = arr.size()/2;

        int n  = freq.size(), totalE = 0, sum1 = 0, count = 0;
        int left = freq.size()-1;
        while(left >= 0 and sum1 < half){
            sum1 += freq[left];
            ++count;
            --left;
        }
        // if(sum1>=half)
        return count;
        
    }
};



















