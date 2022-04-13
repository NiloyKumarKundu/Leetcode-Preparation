class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int left = 0, right = n - 1, top = 0, down = n - 1, value = 1;
        
        while (left <= right && top <= down) {
            for (int i = left; i <= right; i++) {
                ans[top][i] = value++;
            }
            top++;
            
            for (int i = top; i <= down; i++) {
                ans[i][right] = value++;
            }
            right--;
            
            for (int i = right; i >= left; i--) {
                ans[down][i] = value++;
            }
            down--;
            
            for (int i = down; i >= top; i--) {
                ans[i][left] = value++;
            }
            left++;
        }
        
        return ans;
    }
};