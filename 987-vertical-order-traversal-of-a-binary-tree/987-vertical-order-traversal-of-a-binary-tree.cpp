/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    
    void _print(map<int, map<int, int>> treeMap){
        for(pair<int, map<int, int>> p1: treeMap){
            cout << "(" << p1.first << ",";
            for(pair<int, int> p2: p1.second){
                cout << p2.first << "): " << p2.second << ", "<< endl;
            }
        }
        cout << endl;
    }
    
    class NodeIndex{
        public:
        TreeNode* node;
        int row; 
        int col;
        NodeIndex(TreeNode* node, int row, int col){
            this->node = node;
            this->row = row;
            this->col = col;
        }
    };
    
  
    static bool comparator(pair<int, int>& p1, pair<int, int>& p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
            return p1.first < p2.first;
        }
    
    vector<vector<int>> bfsSolve(TreeNode* root){
        // map<int, multimap<int, int, Comparator>> treeMap;
        vector<vector< pair<int, int> > > treeMap(1000);
        unordered_map<int, pair<int, int>> rowRanges; // {RowNo: {minColIdx, maxColIdx}}
        queue<NodeIndex> Q; // {row, column, value}
        int noOfRows = 0, minRow = INT_MAX, maxRow = INT_MIN;
        
        Q.push(NodeIndex(root,0,0));
        while(!Q.empty()){
            NodeIndex topNode = Q.front();
            Q.pop();
            
            treeMap[topNode.row].push_back(pair<int, int>(topNode.col,topNode.node->val));
            // cout <<  "Size at " << topNode.row << " "<< treeMap[topNode.row].size() << endl;
            noOfRows = max(topNode.row, noOfRows);
            minRow = min(minRow, topNode.col), maxRow = max(maxRow, topNode.col);
            // rowRanges[topNode.row] = pair<int, int>(min(rowRanges[topNode.row].first, topNode.col), 
            //                                         max(rowRanges[topNode.row].first, topNode.col));
            
            if(topNode.node->left) Q.push(NodeIndex(topNode.node->left, topNode.row + 1, topNode.col - 1));
            if(topNode.node->right) Q.push(NodeIndex(topNode.node->right, topNode.row + 1, topNode.col + 1));
        }
        // _print(treeMap);
        int levels = maxRow - minRow + 1;
        vector<vector<int>> answer(levels, vector<int>());
        for(int i = 0; i <= noOfRows; i++){
            sort(treeMap[i].begin(), treeMap[i].end(), comparator);
        }
        
        // cout << "size: " << noOfRows << endl;
        
        int idx = 0;
        for(vector<pair<int, int>> v: treeMap){
            int rowNo = idx, colNo;
            for(pair<int, int> p2: v){
                // cout << p2.first << ", " << p2.second << endl;
                colNo = p2.first - minRow;
                // cout << "colNo: " << colNo  << "minRow: " << minRow << endl;
                answer[colNo].push_back(p2.second);
            }
        }
        
        // for(int i = 0; i <= noOfRows; i++){
        //     int rowNo = i, colNo;
        //     // cout << treeMap[i].size() << endl;
        //     for(int j = 0; j < treeMap[i].size(); j++){
        //         pair<int, int> p2 = treeMap[i][j];
        //         colNo = p2.first - minRow;
        //         cout << "colNo: " << colNo  << "minRow: " << minRow << endl;
        //         answer[colNo].push_back(p2.second);
        //     }
        // }
        
        // for(auto p1: treeMap){
        //     int rowNo = p1.first, colNo;
        //     for(pair<int, int> p2: p1.second){
        //         colNo = p2.first - minRow;
        //         cout << "colNo: " << colNo  << "minRow: " << minRow << endl;
        //         answer[colNo].push_back(p2.second);
        //     }
        // }
        
        return answer;
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return vector<vector<int> >();
        return bfsSolve(root);
    }
};




















