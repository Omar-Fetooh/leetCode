class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     vector<int>ans;
     int n=nums.size();
     if(n<2) return nums;
     else if(n==2)
     {       vector<int>tt;
             tt.push_back(nums[0]);
        if(nums[0]==nums[1]) {
            
             return tt;
        }
        tt.push_back(nums[1]);
        return tt;
     } 
     int cnt=1;
     for(int i=0;i<n-1;i++) {
        if(nums[i]==nums[i+1]){
            cnt++;
            if(i==n-2&&cnt>n/3) ans.push_back(nums[i]);
        }
        else{
            if(cnt>n/3) ans.push_back(nums[i]);
            cnt=1;
        }
     }  
     return ans;
    }
};