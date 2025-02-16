class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int>ans;

        for (int i = nums.size() - 1;i >= 0;i--) {
            while (!st.empty() && st.top() <= nums[i]) st.pop();

            bool flag = false;
            if (st.empty()) {
                for (int j = 0;j < i;j++) {
                    if (nums[j] > nums[i]) {
                        ans.push_back(nums[j]);
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    ans.push_back(-1);
                }
            }
            else {
                ans.push_back(st.top());
            }

            st.push(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;   
    }
};