class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sum1(nums.size());
        vector<int> sum2(nums.size());
        int n = nums.size();

        sum2[n - 1] = nums[n - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            sum2[i] += sum2[i + 1] + nums[i];
        }

        sum1[0] = nums[0];
        if (sum1[0] == sum2[0])
            return 0;
        for (int i = 1; i < nums.size(); i++) {
            sum1[i] += sum1[i - 1] + nums[i];
            if (sum1[i] == sum2[i])
                return i;
        }
        return -1;
    }
};