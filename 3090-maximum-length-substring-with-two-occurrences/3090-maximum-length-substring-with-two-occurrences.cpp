class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        string tmp = "";
        int maxi = 0;
        while (r < s.size()) {
            mp[s[r]]++;
            ++r;
            while (mp[s[r - 1]] > 2) {
                --mp[s[l]];
                ++l;
            }
            maxi = max(maxi, r - l);
        }
        return maxi;
    }
};