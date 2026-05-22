class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 1;
        while (l < n) {
            while (r < n && nums[r] == nums[r - 1]) {
                ++r;
            }
            if (r >= n)
                break;
            nums[++l] = nums[r];
            ++r;
        }
        return l + 1;
    }
};