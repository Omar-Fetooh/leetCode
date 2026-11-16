class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        if (k == 0)
            return ans;

        vector<int> duplicated(n * 2);
        for (int i = 0; i < n; i++) {
            duplicated[i] = duplicated[i + n] = code[i];
        }
        if (k > 0) {

            for (int i = 0; i < n; i++) {
                int temp = k;
                int sum = 0;
                int j = i + 1;

                while (temp--) {
                    sum += duplicated[j];
                    ++j;
                }
                ans[i] = sum;
            }
        } else {
            for (int i = n; i < 2 * n; i++) {
                int temp = -1 * k;
                int sum = 0;
                int j = i - 1;
                while (temp--) {
                    sum += duplicated[j];
                    --j;
                }
                ans[i - n] = sum;
            }
        }
        return ans;
    }
};