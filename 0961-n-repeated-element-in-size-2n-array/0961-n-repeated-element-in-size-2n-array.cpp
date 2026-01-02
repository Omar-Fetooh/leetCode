class Solution {
public:
   	int repeatedNTimes(vector<int>& nums) {
		vector<int>freq(10005,0);
		for (auto x : nums) {
			freq[x]++;
			if (freq[x] >= nums.size() / 2) return x;
		}
        return 0;
	}
};