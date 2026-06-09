class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs[0]=="") return "";
        sort(strs.begin(), strs.end());
        string ans;
        char now = strs[0][0];
        for (int i = 0,j=0;i < strs.size();i++) {
            if (now != strs[i][j]) break;
            else if (i == strs.size() - 1 && now == strs[i][j])
            {
                ans += now;
                ++j;
                if (j > strs[0].size()-1) break;
                now = strs[0][j];
                i = 0;
            }

        }
        return ans;
    }
};