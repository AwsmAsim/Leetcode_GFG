class Solution {
    
    
    void printList(queue<int> lst, string listName){
        cout << listName << ": ";
        while(lst.size()>0){
            cout << lst.front() << " ";
            lst.pop();
        }
        cout << endl;
    }
    
public:
    string minRemoveToMakeValid(string s) {
        queue<int> openingBracketsIdx, invalidBracketsIdx;
        string answer;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='(') openingBracketsIdx.push(i);
            else if(s[i]==')'){
                if(openingBracketsIdx.size()==0){
                    invalidBracketsIdx.push(i);
                }else{
                    openingBracketsIdx.pop();
                }
            }
        }
        
        // printList(openingBracketsIdx, "Opening Brackets");
        // printList(invalidBracketsIdx, "Invalid Brackets");
        
        for(int i = 0; i < s.size(); i++){
            if(openingBracketsIdx.size() > 0 and openingBracketsIdx.front()==i){
                openingBracketsIdx.pop();
            } 
            else if (invalidBracketsIdx.size() > 0 and invalidBracketsIdx.front()==i){
                invalidBracketsIdx.pop();
            }
            else answer += s[i];
        }
        
        
        return answer;
        
    }
};