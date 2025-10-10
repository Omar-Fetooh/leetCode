class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        int i = 0, j = 0;
        while (j<nums.size() && j - i <= k) {
            mp[nums[j]]++;
            if (mp[nums[j]] > 1)
                return true;
            ++j;
        }

        while (j < nums.size()) {
            mp[nums[i]]--;
            ++i;
            mp[nums[j]]++;
            if (mp[nums[j]] > 1)
                return true;
            ++j;
        }
        return false;
    }
};