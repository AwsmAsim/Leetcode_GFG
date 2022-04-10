class Solution {
    
    void print1d(vector<int> lst){
        cout << endl;
        for(auto a: lst) cout << a <<" " ;
        cout << endl;
    }
    
public:
    int calPoints(vector<string>& ops) {
        
        vector<int> sumArray;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i]=="+"){
                int newScore = sumArray[sumArray.size()-1] + sumArray[sumArray.size()-2]; 
                sumArray.push_back(newScore);
            }else if(ops[i]=="D"){
                int newScore = sumArray[sumArray.size()-1] * 2; 
                sumArray.push_back(newScore);
            }else if(ops[i]=="C"){
                sumArray.pop_back();
            }else{
                // int number=0;
                // bool neg = false;
                // for(auto digit: ops[i]){
                //     if(digit == '-') {
                //         neg = true;
                //         continue;
                //     }
                //     number += number*10 + (int)(digit)-48;
                // }
                // if(neg) number *= -1;
                // sumArray.push_back(number);
                sumArray.push_back(stoi(ops[i]));
            }
            // print1d(sumArray);
        }
        
        int sum1=0;
        for(auto element: sumArray) sum1 += element;
        return sum1;
    }
};