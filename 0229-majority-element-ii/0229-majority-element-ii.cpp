class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = INT_MIN, cnt1 = 0;
        int candidate2 = INT_MIN, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 && nums[i] != candidate2) {
                candidate1 = nums[i];
                cnt1 = 1;
            } else if (cnt2 == 0 && nums[i] != candidate1) {
                candidate2 = nums[i];
                cnt2 = 1;
            } else if (nums[i] == candidate1)
                ++cnt1;
            else if (nums[i] == candidate2)
                ++cnt2;
            else {
                --cnt1;
                --cnt2;
            }
        }
        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate1)
                cnt1++;
            else if (nums[i] == candidate2)
                ++cnt2;
        }
        if (cnt1 > nums.size() / 3)
            ans.push_back(candidate1);
        if (cnt2 > nums.size() / 3)
            ans.push_back(candidate2);
        return ans;
    }
};