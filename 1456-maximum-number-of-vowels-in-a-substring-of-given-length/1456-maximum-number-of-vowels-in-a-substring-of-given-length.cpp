class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        set<char> st = {'a', 'o', 'u', 'i', 'e'};
        int l = 0, r = 0, curr = 0, maxi = 0;
        while (r - l < k) {
            if (st.find(s[r]) != st.end()) {
                ++curr;
                maxi = max(maxi, curr);
            }
            ++r;
        }
        --r;
        while (r < n) {
            ++r;
            if (st.find(s[r]) != st.end()) {
                ++curr;
            }
            if (st.find(s[l]) != st.end()) {
                --curr;
            }
            maxi = max(maxi, curr);
            ++l;
        }

        return maxi;
    }
};