class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())return false;
        string temp1 = s, temp2 = goal;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        if (temp1 != temp2) return false;
        int i = 0,j=0;
        int cnt = goal.size();
        while (s.substr(i, cnt) != goal) {
            s.push_back(s[i]);
            ++i;
            if (i > cnt) return false;
        }
        return true;
    }
};