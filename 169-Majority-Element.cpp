class Solution {
public:
    int majorityElement(vector<int>& nums) {
      // OPTIMAL SOLUTION Moore's Voting Algorithm
      int ele=nums[0],cnt=0;
      for(int i=0;i<nums.size();i++){
        if(cnt==0){ // starting a new section
            cnt=1;
            ele=nums[i];
        }
        else if(ele==nums[i])++cnt;
        else --cnt;
      }
      return ele;
    }
};

//  MY INTIAL SOLUTION
//   int n=nums.size();
//         map<int,int>mp;
//         int maxi=-50000,maxiIndex;
//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;
//             if(mp[nums[i]]>=maxi) {
//                 maxi=mp[nums[i]];
//                 maxiIndex=nums[i];
//             }
//         }
//         return maxiIndex;