class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        for(int j = 0; j < numRows; j++){
            vector<int> row;
            for(int i = 0; i <= j; i++){
                if(i==0 or i == j) row.push_back(1);
                else row.push_back(triangle[j-1][i-1] + triangle[j-1][i]);
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};