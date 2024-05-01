class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        vector<int>arr;
        int i=n-k;
        int temp=i;
        for(;i<n;i++){
            arr.push_back(nums[i]);
        }
        for(int j=0;j<temp;j++){
            arr.push_back(nums[j]);
        }
        nums=arr;
    }
};