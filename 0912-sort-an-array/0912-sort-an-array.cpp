class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
    void merge(vector<int>& nums, int l, int mid, int r) {
        int i = l, j = mid + 1;
        vector<int> temp;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid)
            temp.push_back(nums[i++]);
        while (j <= r)
            temp.push_back(nums[j++]);

        for (int i = l; i <= r; i++) {
            nums[i] = temp[i - l];
        }
    }
};