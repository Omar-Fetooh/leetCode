class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        map<char, int>mp;
        int maxi = 0;
        for (int l = 0, r = 0;r < s.size();r++) {
             if (mp.count(s[r])&&mp[s[r]] >= l)  {
                l = mp[s[r]] + 1;
            }
            maxi = max(maxi, r - l + 1);
            mp[s[r]] = r;
        }
        return maxi;
    }
};