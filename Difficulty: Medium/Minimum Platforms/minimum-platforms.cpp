class Solution {
	public:
	int minPlatform(vector<int>& arr, vector<int>& dep) {
		// code here
		sort(arr.begin(), arr.end());
		sort(dep.begin(), dep.end());
		
		int maxCnt = 0, cnt = 0;
		int i = 0, j = 0, n = arr.size();
		while (i < n) {
			if (arr[i] <= dep[j]) {
				++cnt;
				++i;
			}
			else {
				--cnt;
				++j;
			}
			maxCnt = max(maxCnt, cnt);
		}
		return maxCnt;
	}
};
