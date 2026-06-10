class Solution {
	public:
	int nthRoot(int n, int m) {
		// Code here
		if (m <= 1 || n <=1)
			return m;
		int low = 1, high = (m / 2)+1;
		while (low <= high) {
			int mid = (low + high) / 2;
			long long res = pow(mid, n);
			if (res == m)
				return mid;
			else if (res > m)
				high = mid - 1;
			else
				low = mid + 1;
		}
		return - 1;
	}
};
