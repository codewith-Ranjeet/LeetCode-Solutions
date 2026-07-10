class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> dup;

        for (int i = 0; i < 9; i++) {
            dup.clear();
            // validate rows
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (dup.contains(board[i][j]))
                    return false;
                dup.insert(board[i][j]);
            }
            dup.clear();
            // validate columns
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.')
                    continue;
                if (dup.contains(board[j][i]))
                    return false;
                dup.insert(board[j][i]);
            }
        }
        // validate cells
        for (int cell = 0; cell < 9; cell++) {
            dup.clear();
            int row_start = 3 * (cell / 3);
            int col_start = 3 * (cell % 3);

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char current = board[row_start + i][col_start + j];

                    if (current == '.')
                        continue;
                    if (dup.contains(current))
                        return false;
                    dup.insert(current);
                }
            }
        }

        return true;
    }
};