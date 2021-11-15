// Brute force
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> v;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    v.push_back({i, j});
                }
            }
        }
        int ind = 0;
        for (auto i : v) {
            int row = i.first;
            int col = i.second;
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[row][j] = 0;
            }
            
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j][col] = 0;
            }
        }
    }
};


// Optimal 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), col0 = 1;
        
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                col0 = 0;
            }
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (col0 == 0) {
                matrix[i][0] = 0;
            }
        }
    }
};