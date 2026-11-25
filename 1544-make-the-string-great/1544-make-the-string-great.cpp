class Solution {
public:
string makeGood(string s) {
	 stack<char> st;
	 for (int i = 0;i < s.size();i++) {
		 st.push(s[i]);

		 if (st.size()>1)
		 {
			 char first = st.top();
			 st.pop();
			 char second = st.top();
			 st.pop();

			 if (abs(first - second) == 32) {
				 continue;
			 }
			 else {
				 st.push(second);
				 st.push(first);
			 }
		 }
	 }
	 string ans;
	 while (!st.empty()) {
		 ans += st.top();
		 st.pop();
	 }
	 reverse(ans.begin(), ans.end());
	 return ans;
 }
};