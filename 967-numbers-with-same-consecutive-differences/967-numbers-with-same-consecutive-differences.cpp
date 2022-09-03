class Solution {
    inline bool checkDigits(int number, int n){
        if(number >= pow(10, n-1) and number < pow(10, n)) return true;
        return false;
    }
    
    vector<int> formNumbers(vector<vector<int>> graph, int n){
        queue<int> Q;
        vector<int> answer;
        
        for(int i = 1; i <= 9; i++){
            Q.push(i);
            while(!Q.empty()){
                int topNode = Q.front();
                Q.pop();
                if(checkDigits(topNode, n)){
                    answer.push_back(topNode);
                    continue;
                }
                for(int nbr: graph[topNode%10]){
                    Q.push(topNode*10 + nbr);
                }
            }
        }
        
        return answer;
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<vector<int> > arr(10, vector<int>());
        
        for(int i = 0; i <= 9; i++){
            int largerNum = i + k;
            int smallerNum = i - k;
            if(largerNum >= 0 and largerNum < 10) arr[i].push_back(largerNum);
            if(smallerNum >= 0 and smallerNum < 10 and largerNum != smallerNum) arr[i].push_back(smallerNum);
        }

        // cout << "Graph: " << endl;
        // int nodeNum = 0;
        // for(vector<int> row: arr){
        //     cout << nodeNum  << ": ";
        //     for(int num: row) cout << num << ", ";
        //     cout << endl;
        //     ++nodeNum;
        // }
        
        
        return formNumbers(arr, n);
    }
};

// 0 3 6 9 
// 1 4 7
// 2 5 8
