class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = nums[0];
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] < nums[i]) {
                mini = nums[i + 1];
                break;
            }
        }

        return mini;
    }
};