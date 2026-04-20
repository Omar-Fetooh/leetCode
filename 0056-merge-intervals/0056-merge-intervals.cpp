class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        vector<int> currentInterval = intervals[0];
        if(intervals.size()==1) return intervals;
        int i = 0;
        while (i < intervals.size() - 1) {
            if (intervals[i + 1][0] <= currentInterval[1]) {
                currentInterval[1] =
                    max(intervals[i + 1][1], currentInterval[1]);
                ++i;
                if (i == intervals.size() - 1)
                    ans.push_back(currentInterval);
            } else {
                ans.push_back(currentInterval);
                currentInterval = intervals[i + 1];
                ++i;
                if (i == intervals.size() - 1)
                    ans.push_back(currentInterval);
            }
        }

        return ans;
    }
};