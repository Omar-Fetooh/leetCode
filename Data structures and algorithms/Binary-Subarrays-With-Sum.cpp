class Solution {
public:
       
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

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sol(nums,goal)- sol(nums,goal-1);
    }
};