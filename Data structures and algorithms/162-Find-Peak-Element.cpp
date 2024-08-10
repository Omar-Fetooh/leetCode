class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        else if (n==2){
            if(nums[0]>nums[1]) return 0;
            else return 1;
        }
        else {
            int low=0,high=n-1;
            while(low<=high){
                int mid=((low+high)/2);
                 if (mid == 0 && nums[mid] > nums[mid + 1]) return 0;
                else if(mid==0&&nums[mid+1]>nums[mid]) return 1;
                if(mid==n-1||nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]) return mid;
                else if(nums[mid+1]>nums[mid])low=mid+1;
                else if(nums[mid-1]>nums[mid])high=mid-1;
            }
        }
        return 0;
    }
};