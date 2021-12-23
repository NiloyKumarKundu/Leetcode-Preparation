class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        vector<vector<int>> V(c, vector<int> (r));
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                V[i][j] = matrix[j][i];
            }
        }
        return V;
    }
};