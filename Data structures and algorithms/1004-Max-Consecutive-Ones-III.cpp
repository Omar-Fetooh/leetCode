class Solution {
public:
int longestOnes(vector<int>& nums, int k) {
    int maxi = 0, sum = 0, l = 0, r = 0;
    while (r < nums.size()) {
        while (r < nums.size() && (k || nums[r] == 1)) {  
            if (nums[r] == 0) k--;

           r++;
           sum++;
        }
        maxi = max(maxi, sum);
        if (r < nums.size()) {
            if (nums[l] == 0)
                k++;  
            l++;
            sum--;
        }
    }
    return maxi;
}
};