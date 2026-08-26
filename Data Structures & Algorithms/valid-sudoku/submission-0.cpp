class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            unordered_set<char> row;
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (row.count(board[i][j])) {
                    return false;
                }
                row.insert(board[i][j]);
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            unordered_set<char> col;
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (col.count(board[j][i])) {
                    return false;
                }
                col.insert(board[j][i]);
            }
        }
        for (int square = 0; square < 9; ++square) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') {
                        continue;
                    }
                    if (seen.count(board[row][col])) {
                        return false;
                    }
                    seen.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
