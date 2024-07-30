class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
     int cnt=0;
     int maxi=-1;
     for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            ++cnt;
        }
        else if(nums[i]!=1){
            maxi=max(maxi,cnt);
            cnt=0;
        }
     }   
     return max(maxi,cnt);
    }
};