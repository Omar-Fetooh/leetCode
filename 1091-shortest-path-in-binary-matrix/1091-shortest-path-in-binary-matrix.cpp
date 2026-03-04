class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1&&grid[0][0]==0) return 1;
        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;
        vector<vector<int>> dist(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i].push_back(1e9);
            }
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        vector<int> rows = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> cols = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty()) {
            int r = q.front().second.first;
            int c = q.front().second.second;

            int d = q.front().first;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nrow = r + rows[i];
                int ncol = c + cols[i];
                if (nrow == n - 1 && ncol == n - 1)
                    return d + 1;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0) {
                    if (d + 1 < dist[nrow][ncol]) {
                        dist[nrow][ncol] = d + 1;
                        q.push({d + 1, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};