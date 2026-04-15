class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            if (mp.count(target - nums[i]) > 0) {
                auto it = mp.find(target - nums[i]);
                return {i, it->second};
            } else {
                mp.insert({nums[i], i});
            }
        }
        return {0, 0};
    }
};