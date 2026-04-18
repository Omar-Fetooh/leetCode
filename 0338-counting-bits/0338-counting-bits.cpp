class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        for (int i = 1; i < n + 1; i++) {
            ans[i] = ans[i / 2] + (i % 2);
        }
        return ans;
    }

    // My first solution
    // vector<int> countBits(int n) {
    //     vector<int> ans;
    //     for (int i = 0; i <= n; i++) {
    //         int n = i, cnt = 0;
    //         while (n > 0) {
    //             int res = n % 2;
    //             if (res)
    //                 cnt++;
    //             n /= 2;
    //         }
    //         ans.push_back(cnt);
    //     }
    //     return ans;
    // }
};