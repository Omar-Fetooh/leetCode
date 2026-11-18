class Solution {
public:
    bool isNice(string s) {
        for (int i = 0; i < s.size(); i++) {
            bool flag = false;
            for (int j = 0; j < s.size(); j++) {
                if (abs(s[i] - s[j]) == 32) {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
                return false;
        }
        return true;
    }

    string longestNiceSubstring(string s) {
        string maxi = "";
        int maxiCount = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = s.size() - 1; j > i; j--) {
                string temp = s.substr(i, j - i + 1);
                if (isNice(temp)) {
                    if (temp.size() > maxiCount) {
                        maxiCount = temp.size();
                        maxi = temp;
                    }
                }
            }
        }
        if (maxiCount)
            return maxi;
        return "";
    }
};