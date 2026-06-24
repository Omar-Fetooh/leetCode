class Solution {
public:
    string reverseWords(string s) {
	reverse(s.begin(), s.end());
	string ans;

	for (int i = 0;i < s.size();i++) {
		string temp;
		while (i < s.size()&& s[i]!=' ')
		{
			temp += s[i];
			++i;
		}
		if (temp.size()) {
			reverse(temp.begin(), temp.end());
			ans += " " + temp;
		}
	}
	return ans.substr(1);
}
};