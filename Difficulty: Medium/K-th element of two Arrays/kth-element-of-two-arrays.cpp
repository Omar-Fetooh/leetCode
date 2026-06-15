class Solution {
	public:
	int kthElement(vector<int>& a, vector<int>& b, int k) {
		// code here
		for (int i = 0; i < b.size(); i++) {
			a.push_back(b[i]);
		}
		sort(a.begin(), a.end());
		return a[k - 1];
	}
};
