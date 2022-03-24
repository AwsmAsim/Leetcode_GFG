class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> answer;
        int carry = 0, curr, i;
        for(i = digits.size()-1; i >= 0; i--){
            curr = digits[i] + 1;
            if(curr>=10){
                carry = 1;
            }else carry = 0;
            answer.push_back(curr%10);
            if(carry == 0) break;
        }
        --i;
        for(; i >= 0; i--){
            answer.push_back(digits[i]);
        }
        if(carry) answer.push_back(1);
        reverse(answer.begin(), answer.end());
        return answer;
    }
};