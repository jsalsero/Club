/*
0-  1 1 1 1   
1-  1 2 2 1
2-  1 2 2 1
3-  1 1 1 1

0 1
1 2

1 1 1 1 1 1
1 2 2 2 2 1
1 2 3 3 2 1
1 2 3 3 2 1
1 2 2 2 2 1
1 1 1 1 1 1

len = 6
0 4
1 3
2 2


1 2 3
4 5 6
7 8 9

7 4 1
8 5 2
9 6 3

7 8 1
4 5 2
9 6 3

*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        
        for (int layer = 0; layer < len/2; ++layer) {
            for (int i = layer; i < len - 1 - layer; ++i) swap(matrix[i][layer],           matrix[len - 1 - layer][i]);
            for (int i = layer; i < len - 1 - layer; ++i) swap(matrix[len - 1 - layer][i], matrix[len - 1 - i][len - 1 - layer]);
            for (int i = layer; i < len - 1 - layer; ++i) swap(matrix[len - 1 - i][len - 1 - layer], matrix[layer][len - 1 - i]);
        }
    }
};
