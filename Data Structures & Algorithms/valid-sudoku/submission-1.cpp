class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> squares;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int val = board[i][j];
                if (val == '.') continue;
                if (rows[i].count(val) || cols[j].count(val) || squares[{i / 3, j / 3}].count(val)) return false;
                rows[i].insert(val);
                cols[j].insert(val);
                squares[{i / 3, j / 3}].insert(val);

            }
        }
        return true;
    }
};
