class Solution {
public:
    int frob(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind == 0)
            return nums[ind];
        if (ind < 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int pick = nums[ind] + frob(ind - 2, nums, dp);
        int notPick = frob(ind - 1, nums, dp);
        return dp[ind] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> temp1(nums.begin(), nums.end() - 1);
        vector<int> temp2(nums.begin() + 1, nums.end());

        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);

        return max(frob(temp1.size() - 1, temp1, dp1),
                   frob(temp2.size() - 1, temp2, dp2));
    }
};