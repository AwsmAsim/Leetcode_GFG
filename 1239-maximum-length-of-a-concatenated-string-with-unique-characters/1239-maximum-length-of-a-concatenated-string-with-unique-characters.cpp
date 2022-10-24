class Solution {
    
    bool doesExist(string toCheck, string givenString){
        vector<bool> boolArr(26, false);
        
        for(char ch: givenString){
            if(boolArr[ch - 'a']) return true;
            boolArr[ch - 'a'] = true; 
        }
        
        for(char ch: toCheck){
            if(boolArr[ch - 'a']) return true;
            boolArr[ch - 'a'] = true;
        }
        
        return false;
    }
    
    int solveRec(int idx, string& curString, vector<string>& arr){
        
        if(idx == arr.size()){
            // cout << curString << endl;
            return curString.size();
        }
        
        int pick = 0, notPick = 0;
        notPick = solveRec(idx + 1, curString, arr);
        if(!doesExist(arr[idx], curString)){
            curString += arr[idx];
            pick = solveRec(idx + 1, curString, arr);
            for(int i = 0; i < arr[idx].size(); ++i) curString.pop_back();
        }
        
        
        return max(pick, notPick);
        
    }
    
public:
    int maxLength(vector<string>& arr) {
        
        string curString = "";
        return solveRec(0, curString, arr);
        return 0;
    }
};