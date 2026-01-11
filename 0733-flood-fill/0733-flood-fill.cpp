class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();
        int firstColor = image[sr][sc];
        queue<pair<int, int>> q;
        image[sr][sc] = color;
        q.push({sr, sc});
        vector<vector<int>> visited(n, vector<int>(n));
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vector<int> drow = {-1, 0, 1, 0};
            vector<int> dcol = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    image[nrow][ncol] == firstColor &&
                    visited[nrow][ncol] != 1) {
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return image;
    }
};