class Solution {
public:
  int jump(vector<int>& nums) {
    int jumps = 0, maxi = 0, maxiIndex = 0;
    bool solved = false;
    int n = nums.size();
    if(n==1) return 0;
    for (int i = 0;i < n;) {
        if (nums[i] >= n - i - 1) {
            ++jumps;
            break;
        }
        maxi = 0;
        maxiIndex = 0;
       for (int j = i + 1;j <= i + nums[i] && j < n;j++) {
            if (j + nums[j] > maxi) {
                maxi = j + nums[j];
                maxiIndex = j;
            }
        }
        i = maxiIndex;
        ++jumps;

    }
    return jumps;
}
};