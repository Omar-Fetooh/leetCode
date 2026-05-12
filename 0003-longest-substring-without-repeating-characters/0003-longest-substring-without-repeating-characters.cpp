class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int maxi = 0;
        int i = 0, j = 0;
        while (j < s.size()) {
            if (hash[s[j]] != -1) {
                if (hash[s[j]] >= i) {
                    i = hash[s[j]] + 1;
                }
            }
            maxi = max(maxi, j - i + 1);
            hash[s[j]] = j;
            ++j;
        }
        return maxi;
    }
};