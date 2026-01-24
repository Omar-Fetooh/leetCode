class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited,
             vector<vector<int>>& board, vector<int>& drow, vector<int>& dcol) {
        visited[row][col] = 1;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                board[nrow][ncol] == 1 && visited[nrow][ncol] != 1) {
                dfs(nrow, ncol, visited, board, drow, dcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) {
                dfs(0, i, visited, grid, drow, dcol);
            }
            if (grid[m - 1][i] == 1) {
                dfs(m - 1, i, visited, grid, drow, dcol);
            }
        }

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                dfs(i, 0, visited, grid, drow, dcol);
            }
            if (grid[i][n - 1] == 1) {
                dfs(i, n - 1, visited, grid, drow, dcol);
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0 && grid[i][j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};