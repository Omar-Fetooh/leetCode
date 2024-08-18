class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
    int maxi=*max_element(nums.begin(),nums.end());
     int low=0,high=maxi;
     while(low<=high){
         double sum=0;
        int mid=(low+high)/2;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/mid);
        }
        if(sum>threshold) low=mid+1;
        else high=mid-1;
     }   
     return low;
    }
};