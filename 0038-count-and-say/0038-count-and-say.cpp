class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        if (n == 1)
            return s;
        for (int i = 2; i <= n; i++) {
            string news = "";
            int cnt = 1;
            for (int j = 0; j < s.size(); j++) {
                while (j + 1 < s.size() && s[j] == s[j + 1]) {
                    cnt++;
                    ++j;
                }
                news += to_string(cnt);
                news += s[j];
                cnt = 1;
            }
            s = news;
        }
        return s;
    }
};