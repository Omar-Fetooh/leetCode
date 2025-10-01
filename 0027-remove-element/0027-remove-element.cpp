class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                --k;
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
                --i;
            }
        }
        return k;
    }
};