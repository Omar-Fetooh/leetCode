class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int>last = intervals[0];
        int ans = 0;
        for (int i = 1;i < intervals.size();i++) {
            if (intervals[i][0] >= last[0] && intervals[i][0] < last[1]) {
                ++ans;
                if (intervals[i][1] < last[1]) {
                    last = intervals[i];
                }
            }
            else {
                last = intervals[i];
            }
        }
        return ans;
    }
};