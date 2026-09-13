class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<set<int>>> subsets(3, vector<set<int>>(3));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    if (subsets[i / 3][j / 3].count(board[i][j]) == 1)
                        return false;
                    else {
                        subsets[i / 3][j / 3].insert(board[i][j]);
                    }

                    for (int k = j + 1; k < 9; k++) {
                        if (board[i][k] == board[i][j])
                            return false;
                    }

                    for (int k = i + 1; k < 9; k++) {
                        if (board[k][j] == board[i][j])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};