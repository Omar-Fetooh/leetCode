class Solution {
public:

//    static bool proceed(vector<int>a, vector<int>b) {
//         return a[0] < b[0];
//     }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
	vector<vector<int>>ans;
	int i = 0;
	int n = intervals.size();
	vector<int>curr = intervals[0];
	while (i<n)
	{
		while (i < n && intervals[i][0] >= curr[0] && intervals[i][0] <= curr[1]) {
			curr[0] = min(curr[0], intervals[i][0]);
			curr[1] = max(curr[1], intervals[i][1]);
			++i;
		}
		ans.push_back(curr);
		if(i<n)	curr = intervals[i];
		++i;
		if (i == n) {
			ans.push_back(curr);
		}
	}
	return ans;
    }
};