class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int n = s.size();
        unordered_map<char, int> mp = {
            {'V', 5}, {'L', 50}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') {
                if (i < n && s[i + 1] == 'V') {
                    sum += 4;
                    ++i;
                } else if (i < n && s[i + 1] == 'X') {
                    sum += 9;
                    ++i;
                } else
                    sum += 1;
            } else if (s[i] == 'X') {
                if (i < n && s[i + 1] == 'L') {
                    sum += 40;
                    ++i;
                } else if (i < n && s[i + 1] == 'C') {
                    sum += 90;
                    ++i;
                } else
                    sum += 10;
            } else if (s[i] == 'C') {
                if (i < n && s[i + 1] == 'D') {
                    sum += 400;
                    ++i;
                } else if (i < n && s[i + 1] == 'M') {
                    sum += 900;
                    ++i;
                } else
                    sum += 100;
            } else
                sum += mp[s[i]];
        }
        return sum;
    }
};