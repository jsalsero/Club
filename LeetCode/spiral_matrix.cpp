// https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector< pair<int, int> > moves = {
            {0,  1},
            {1,  0},
            {0, -1},
            {-1, 0}
        };
        
        int totalRow = matrix.size();
        int totalCol = matrix[0].size();
        
        int col = 0;
        int row = 0;
        const int visited = 101;
        
        int cont = 0;
        int idxMv = 0;
        bool undo = false;
        vector<int> answer(totalRow * totalCol);
        
        while (matrix[row][col] != visited) {
            answer[cont++] = matrix[row][col];
            matrix[row][col] = visited;
            
            if (cont == totalRow * totalCol)
                break;
            
            row += moves[idxMv].first;
            col += moves[idxMv].second;
            
            // is this order relevant?
            undo = false;
            undo |= (row >= totalRow || row < 0);
            undo |= (col >= totalCol || col < 0);
            undo |= (!undo && matrix[row][col] == visited);
            
            if (undo) {
                row -= moves[idxMv].first;
                col -= moves[idxMv].second;
                
                idxMv = (idxMv + 1) % 4;
                row += moves[idxMv].first;
                col += moves[idxMv].second;
            }
        }

        return answer;
    }
};
