class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>vans;
        for (int i = 0; i < (1<<nums.size()); i++)
        {
            vector<int>temp;
            int n = i;
            int j = 0;
            while (n > 0) {
                if (n & 1)temp.push_back(nums[j]);
                n = n >> 1;
                j++;
            }

            vans.push_back(temp);
        }
        return vans;
    }
};