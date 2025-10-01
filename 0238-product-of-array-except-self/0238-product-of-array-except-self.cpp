class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int mul = 1;
        for (auto x : nums) {
            mul *= x;
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                long long mul2 = 1;
                for (int j = 0; j < nums.size(); j++) {
                    if (j == i)
                        continue;
                    mul2 *= nums[j];
                }
                ans.push_back(mul2);
            } else {
                ans.push_back(mul / nums[i]);
            }
        }
        return ans;
    }
};