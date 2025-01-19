class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int Xorr = 0;
        int N = nums.size();
        for (int i = 0;i < N;i++) Xorr = Xorr ^ nums[i];

        int rightMost = (Xorr & Xorr - 1) ^ Xorr;

        long long int b1 = 0, b2 = 0;
        for (int i = 0;i < N;i++) {
            if (nums[i] & rightMost) b1 = b1 ^ nums[i];
            else b2 = b2 ^ nums[i];
        }

        int ans1=b1,ans2=b2;
        vector<int>v = {ans1,ans2};

        return v;
    }
};