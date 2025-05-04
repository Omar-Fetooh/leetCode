class Solution {
public:
    bool canJump(vector<int>& nums) {
         int balance = nums[0];
         for (int i = 0;i < nums.size();i++) {
            --balance;
            balance = max(balance, nums[i]);
            if (balance == 0 && i < nums.size()-1) return false;
        }
        return true;
    }
};