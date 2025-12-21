class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<long long, pair<int, int>>> vp(points.size());
        for (int i = 0; i < points.size(); i++) {
            long long x = points[i][0];
            long long y = points[i][1];

            long long dist = x * x + y * y;
            vp[i] = {dist, {points[i][0], points[i][1]}};
        }
        sort(vp.begin(), vp.end());
        vector<vector<int>> ans(k, {0, 0});
        for (int i = 0; i < k; i++) {
            ans[i][0] = vp[i].second.first;
            ans[i][1] = vp[i].second.second;
        }
        return ans;
    }
};