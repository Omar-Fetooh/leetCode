class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf = 0,l=0,r=0;
        int maxL = 0;
        int hash[26] = { 0 };

        while (r < s.size()) {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);
            while ((r - l + 1) - maxf > k) {
                hash[s[l] - 'A']--;
                ++l;
                maxf = 0;
                for (int i = 0;i < 26;i++)maxf = max(maxf, hash[i]);
            }
            if ((r - l + 1) - maxf <= k) {
                maxL = max(maxL, r - l + 1);
            }
            ++r;
        }
        return maxL;
    }
};