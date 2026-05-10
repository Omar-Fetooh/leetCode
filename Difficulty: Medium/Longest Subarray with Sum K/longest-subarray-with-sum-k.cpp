class Solution {
	public:
	int longestSubarray(vector<int>& arr, int k) {
		// code here
		int maxi = 0;
		map<long long, int>mp;
		
		long long sum = 0;
		for (int i = 0; i < arr.size(); i++) {
			sum += arr[i];
			if (sum == k) {
				maxi = max(maxi, i + 1);
			}
			else {
				long long rem = sum - k;
				if (mp.find(rem) != mp.end()) {
					int len = i - mp[rem];
					maxi = max(maxi, len);
				}
			}
			if (mp.find(sum) == mp.end()) {
				mp[sum] = i;
			}
		}
		return maxi;
	}
};
