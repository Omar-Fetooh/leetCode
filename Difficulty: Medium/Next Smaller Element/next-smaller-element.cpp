class Solution {
	public:
	vector<int> nextSmallerEle(vector<int>& arr) {
		//  code here
		stack<int> st;
		vector<int> ans;
		int n = arr.size();
		st.push(arr[n - 1]);
		ans.push_back(-1);
		for (int i = n - 2; i >= 0; i--) {
			if (i == n - 1)
				ans.push_back(-1);
			while (!st.empty() && st.top() >= arr[i])
				st.pop();
			if (!st.empty()) {
				ans.push_back(st.top());
			}
			else {
				ans.push_back(-1);
			}
			st.push(arr[i]);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
