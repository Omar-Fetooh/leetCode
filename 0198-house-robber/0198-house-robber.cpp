class Solution {
public:
    int frob(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind == 0 || ind == 1)
            return nums[ind];
        if (dp[ind] != -1)
            return dp[ind];
        int maxi = 0;
        for (int j = ind - 2; j >= 0; j--) {
            int cur = frob(j, nums, dp);
            maxi = max(maxi, cur);
        }
        return dp[ind] = maxi + nums[ind];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        if (nums.size() > 1) {
            dp[1] = nums[1];
            frob(nums.size() - 1, nums, dp);
            frob(nums.size() - 2, nums, dp);
        } else
            frob(nums.size() - 1, nums, dp);

        return *max_element(dp.begin(), dp.end());
    }
};