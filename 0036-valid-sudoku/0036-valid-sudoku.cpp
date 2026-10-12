class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool boxes[9][9] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // Ignore empty cells
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '1';

                // Find the 3x3 box index
                int boxIndex = (i / 3) * 3 + (j / 3);

                // Check for duplicates
                if (rows[i][num] ||
                    cols[j][num] ||
                    boxes[boxIndex][num]) {
                    return false;
                }

                // Mark digit as visited
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[boxIndex][num] = true;
            }
        }

        return true;
    }
};