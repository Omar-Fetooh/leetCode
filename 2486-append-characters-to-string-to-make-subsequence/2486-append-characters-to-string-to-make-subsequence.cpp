class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        for (; i < t.size() && j < s.size();) {
            if (t[i] == s[j])
                ++i;
            j++;
        }
        return t.size() - i;
    }
};