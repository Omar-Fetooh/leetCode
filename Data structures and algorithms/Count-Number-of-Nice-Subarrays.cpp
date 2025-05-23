class Solution {
public:
    bool odd(int n) {
        return n % 2 == 1;
    }

    int sol(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int sum = 0;
        int cnt = 0, l = 0, r = 0;
        
        while (r < nums.size() ) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                ++l;
            }
            cnt = cnt + (r - l + 1);
            ++r;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        for (int i = 0;i < nums.size();i++) {
            nums[i] = odd(nums[i]);
        }
         return  sol(nums, k) - sol(nums, k - 1);
    }
};