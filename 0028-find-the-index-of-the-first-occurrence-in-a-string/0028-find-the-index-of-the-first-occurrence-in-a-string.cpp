class Solution {
public:
 int strStr(string haystack, string needle) {
	for (int i = 0;i < haystack.size();i++) {
		if (haystack[i] == needle[0] && haystack.size() - i >= needle.size() && haystack.substr(i, needle.size()) == needle) return i;
	}
	return -1;
}
};