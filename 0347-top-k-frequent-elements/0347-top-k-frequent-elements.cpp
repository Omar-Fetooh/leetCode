class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int counter = 1;
        if (nums.size() == 1 || nums.size() == k)
            return nums;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                ++counter;
            } else {
                if (!pq.empty() && pq.size() >= k) {
                    int lowest_value = pq.top().first;
                    if (counter > lowest_value) {
                        pq.pop();
                        pq.push({counter, nums[i]});
                        counter = 1;
                    } else
                        counter = 1;
                } else {
                    pq.push({counter, nums[i]});
                    counter = 1;
                }
            }
        }
        if (!pq.empty() && pq.size() >= k) {
            int lowest_value = pq.top().first;
            if (counter > lowest_value) {
                pq.pop();
                pq.push({counter, nums.back()});
            }
        } else {
            pq.push({counter, nums.back()});
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};