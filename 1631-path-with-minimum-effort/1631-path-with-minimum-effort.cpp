class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<int>> diff(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                diff[i].push_back(1e9);
            }
        }

        pq.push({0, {0, 0}});
        diff[0][0] = 0;
        vector<int> rows = {-1, 0, 1, 0};
        vector<int> cols = {0, 1, 0, -1};
        while (!pq.empty()) {
            int dif = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            // if (row == heights.size() - 1, col == heights[0].size() - 1)
            // return dif;

            for (int i = 0; i < 4; i++) {
                int nrow = row + rows[i];
                int ncol = col + cols[i];

                if (nrow >= 0 && nrow < heights.size() && ncol >= 0 &&
                    ncol < heights[0].size()) {
                    int newDiff =
                        max(abs(heights[nrow][ncol] - heights[row][col]), dif);

                    if (newDiff < diff[nrow][ncol]) {
                        diff[nrow][ncol] = newDiff;
                        pq.push({newDiff, {nrow, ncol}});
                    }
                }
            }
        }

        return diff[heights.size() - 1][heights[0].size() - 1];
    }
};