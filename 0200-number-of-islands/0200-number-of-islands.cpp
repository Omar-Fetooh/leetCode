class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    ++count;
                    BFS(row, col, visited, grid);
                }
            }
        }
        return count;
    }

    void BFS(int row, int col, vector<vector<int>>& visited,
             vector<vector<char>>& grid) {
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            vector<vector<int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            for (int i = 0; i < 4; i++) {
                int nrow = row+ delta[i][0];
                int ncol = col+  delta[i][1];

                if (nrow >= 0 && nrow < grid.size() && ncol >= 0 &&
                    ncol < grid[0].size() && grid[nrow][ncol] == '1' &&
                    !visited[nrow][ncol]) {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
};