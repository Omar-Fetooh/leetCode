class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>last;
        for (int i = 0;i < numRows;i++) {
            vector<int>curr = { 1 };
            if (i == 0||i==1) {
                last.push_back(1);
                curr = last;
                ans.push_back(curr);
                continue;
            }
            for (int j = 0;j < last.size() - 1;j++) {
                curr.push_back(last[j] + last[j + 1]);
            }
            curr.push_back(1);
            last = curr;
            ans.push_back(curr);
        }
        return ans;
    }
};