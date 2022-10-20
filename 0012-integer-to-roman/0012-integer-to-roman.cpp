class Solution {
    
public:
    
    map<int, string> intToRomanMap = {
        {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
    } ; 
    
    
//     string solve(int num){
        
//         if(num == 1) return "I";
//         if(num == 2) return "II";
//         if(num == 3) return "III";
        
//         int lBound = prev(intToRomanMap.lower_bound(num))->first;
//         int uBound = (intToRomanMap.lower_bound(num))->first;
        
        
//         string ans;
//         if(abs(lBound - num) <= abs(uBound - num)){
//             ans.push_back(intToRomanMap[lBound]);
//             ans += solve(num - lBound); 
//         }else{
//             ans += solve(uBound - num);
//             ans.push_back(intToRomanMap[uBound]);
//         }
        
//         return ans;
//     }
    
    string solve1(int num){
        
        // cout << num << endl;
        
        if(num == 0) return "";
        if(num == 1) return "I";
        if(num == 4) return "IV";
        if(num == 9) return "IX";
        if(num == 40) return "XL";
        if(num == 90) return "XC";
        if(num == 400) return "CD";
        if(num == 900) return "CM";
        
        // int lBound = prev(intToRomanMap.lower_bound(num))->first;
        int lBound = (intToRomanMap.lower_bound(num))->first;
        if(lBound > num){
            lBound = prev(intToRomanMap.lower_bound(num))->first;
        }if(intToRomanMap.lower_bound(num) == intToRomanMap.end()){
            lBound = prev(intToRomanMap.lower_bound(num))->first;
        }
        
        // cout << "Lower Bound: " << lBound <<endl;
        
        string ans;
        ans+=intToRomanMap[lBound];
        ans += solve1(num - lBound);
        // if(abs(lBound - num) <= abs(uBound - num)){
        //     ans.push_back(intToRomanMap[lBound]);
        //     ans += solve(num - lBound); 
        // }else{
        //     ans += solve(uBound - num);
        //     ans.push_back(intToRomanMap[uBound]);
        // }
        
        return ans;
    }
    
    string intToRoman(int num) {
        return solve1(num);
        
    }
};