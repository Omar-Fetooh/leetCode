class Solution {
  public:
    int minCost(vector<int>& heights) {
        // Code here
        			int n = heights.size();
				map<int, int>mp;
				if (n < 2) return 0;
				else if (n < 3) {
					return abs(heights[1] - heights[0]);
				}
				mp[heights[0]] = 0;
				mp[heights[1]]= abs(heights[1] - heights[0]);
				for (int i = 2;i < n;i++) {
					int mini = min(
						mp[heights[i - 1]] + abs(heights[i] - heights[i - 1]),
						mp[heights[i - 2]] + abs(heights[i] - heights[i - 2])
					);
					mp[heights[i]] = mini;
				}
				return mp[heights[n - 1]];
    }
};