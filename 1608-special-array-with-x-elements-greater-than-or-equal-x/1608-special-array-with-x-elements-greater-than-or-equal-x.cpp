class Solution {
public:
    int counter(int x, vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= x)
                cnt++;
        }
        return cnt;
    }

    int specialArray(vector<int>& nums) {
        int l = 0, r = nums.size();

        while (l <= r) {
            int m = (l + r) / 2;
            int cnt = counter(m, nums);

            if (cnt == m)
                return m;
            else if (cnt > m) {
                l = m + 1;
            } else
                r = m - 1;
        }
        return -1;
    }
};