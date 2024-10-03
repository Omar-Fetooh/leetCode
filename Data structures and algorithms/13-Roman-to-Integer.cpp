class Solution {
public:
int romanToInt(string s) {
        map<char, int>mp = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
        int sum = 0;
        for (int i = 0;i < s.size();i++) {
            if (i < s.length() - 1 && (s[i] == 'I' || s[i] == 'X' || s[i] == 'C')) {
                bool flag = false;
                if (s[i] == 'I') {
                    if (s[i + 1] == 'V') {
                        sum += 4;
                        flag = true;
                        ++i;
                    }
                    else if (s[i + 1] == 'X') {
                        sum += 9;
                        flag = true;
                        ++i;
                    }
                }
                else if (s[i] == 'X') {
                    if (s[i + 1] == 'L') {
                        sum += 40;
                        flag = true;
                        ++i;
                    }
                    else if (s[i + 1] == 'C') {
                        sum += 90;
                        flag = true;
                        ++i;
                    }
                }
                else if(s[i]=='C')
                {
                    if (s[i + 1] == 'D') {
                        sum += 400;
                        flag = true;
                        ++i;
                    }
                    else if (s[i + 1] == 'M') {
                        sum += 900;
                        flag = true;
                        ++i;
                    }
                }
                if (!flag) {
                    sum += mp[s[i]];
                }
                
            }
            else {
                sum += mp[s[i]];
            }
        }
        return sum;
    }
};