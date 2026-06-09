class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string common = strs[0];
        int n = strs.size();
        for (int i = 1; i < n; i++) {
            string temp = "";
            for (int j = 0; j < min(common.size(), strs[i].size()); j++) {
                if (strs[i][j] == common[j]) {
                    temp.push_back(common[j]);
                } else {
                    common = temp;
                }
            }
        }
        return common;
    }
};