class Solution {
    bool isValid (int x, int y, vector<vector<int>>& board) {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dx = {0, 0, 1, -1, 1, 1, -1, -1};
        vector<int> dy = {1, -1, 0, 0, 1, -1, 1, -1};
        
        int m = board.size();
        int n = board[0].size();
        
        for (int row = 0; row < m; row++ ) {
            for (int col = 0; col < n; col++) {
                int count_live_neighbors = 0;
                
                for (int i = 0; i < 8; i++) {
                    int curX = row + dx[i];
                    int curY = col + dy[i];
                    if (isValid(curX, curY, board) && abs(board[curX][curY]) == 1)
                        count_live_neighbors++;
                }
                
                if (board[row][col] == 1 && (count_live_neighbors < 2 || count_live_neighbors > 3))
                    board[row][col] = -1;
                
                if (board[row][col] == 0 && count_live_neighbors == 3)
                    board[row][col] = 2;
            }
        }
        
        for (int row = 0; row < m; row++ ) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] >= 1)
                    board[row][col] = 1;
                else
                    board[row][col] = 0;
            }
        }
    }
};