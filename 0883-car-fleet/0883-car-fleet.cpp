class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vp;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            vp.push_back({position[i], speed[i]});
        }
        sort(vp.rbegin(), vp.rend());
        stack<double> st;
        for (int i = 0; i < n; i++) {
            double time = double(target - vp[i].first) / vp[i].second;
            if (!st.empty() && st.top() < time) {
                st.push(time);
            }
            if (st.empty())
                st.push(time);
        }
        return st.size();
    }
};