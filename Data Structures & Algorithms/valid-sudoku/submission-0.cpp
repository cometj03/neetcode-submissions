class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for (const auto& row : board) {
            vector<int> cnt(10, 0);
            for (char c : row) {
                if (c != '.' && cnt[c - '0']++) return false;
            }
        }

        // check columns
        for (int i = 0; i < 9; i++) {
            vector<int> cnt(10, 0);
            for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                if (c != '.' && cnt[c - '0']++) return false;
            }
        }

        for (int i = 0; i < 9; i+=3) for (int j = 0; j < 9; j+=3) {
            vector<int> cnt(10, 0);
            for (int di = 0; di < 3; di++) for (int dj = 0; dj < 3; dj++) {
                char c = board[i + di][j + dj];
                if (c != '.' && cnt[c - '0']++) return false;
            }
        }
        return true;
    }
};
