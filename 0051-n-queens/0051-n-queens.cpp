class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {

        // check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void nQueen(vector<string>& board, vector<vector<string>>& ans, int row,
                int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(board, row, i, n)) {
                board[row][i] = 'Q';
                nQueen(board, ans, row + 1, n);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        nQueen(board, ans, 0, n);
        return ans;
    }
};