class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        sort(nums.begin(),nums.end());
        int ans;
          int cnt=1;
        for(int i=0;i<nums.size();i++){
          if(nums[i]==nums[i+1]) ++cnt;
          else if(nums[i]!=nums[i+1]&&cnt==2){
            cnt=1;
          }
          else{
                  ans=nums[i];
                break;
          }
        }
        return ans;
    }
};