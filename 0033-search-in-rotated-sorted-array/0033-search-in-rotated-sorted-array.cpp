class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && nums[mid] >= target) {
                    h = mid;
                } else {
                    l = mid + 1;
                }
            } else if (nums[mid] <= nums[h]) {
                if (nums[mid] <= target && nums[h] >= target) {
                    l = mid;
                } else {
                    h = mid - 1;
                }
            }
        }
        return -1;
    }
};