class Solution {
public:
    int beautySum(string s) {
         double sum = 0;
        for (int i = 0;i < s.length();i++) {
            string substr = "";
            map<char, int>mp;
            for (int j = i;j < s.length();j++) {
                substr += s[j];
                mp[s[j]]++;
               // cout << substr<<endl;
                if (mp.size() > 1) {
                    int maxi = 0;
                    int mini = INT_MAX;
                    for (auto ele : mp) {
                        if (ele.second > maxi) maxi = ele.second;
                        if (ele.second < mini) mini = ele.second;
                    }
                    if (maxi > mini) sum += maxi - mini;
                }
            }
        }
        return sum;
    }
};