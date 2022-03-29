class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, left = 0, right = matrix[0].size()-1, bottom = matrix.size() - 1, i;
        int dir = 0;
        vector<int> answer;
        while(top <= bottom and left <= right){
            if(dir == 0){
                i = left;
                while(i <= right){
                    answer.push_back(matrix[top][i]);
                    i++;
                }
                ++top;
            }
            
            else if(dir==1){
                i = top;
                while(i <= bottom){
                    answer.push_back(matrix[i][right]);
                    i++;
                }
                --right;
            }
            
            else if(dir == 2){
                i = right;
                while(i >= left){
                    answer.push_back(matrix[bottom][i]);
                    i--;
                }
                --bottom;
            }
            
            else if(dir == 3){
                i = bottom;
                while(i >= top){
                    answer.push_back(matrix[i][left]);
                    i--;
                }
                ++left;
            }
            // cout << "dir: " << dir << " top, right, bottom, left: " << top <<" "<< bottom <<" "<< right <<" "<< left << endl;
            dir = (dir+1)%4;
        }
        // int i = left;
        // if(top==bottom)
        // while(i<=right){
        //     answer.push_back(matrix[top][i]);
        //     ++i;
        // }
        return answer;
    }
};