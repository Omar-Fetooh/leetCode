class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       mp[0]=1;
       int presum=0,cnt=0;
       for(int i=0;i<nums.size();i++){
        presum+=nums[i];
        int remove=presum-k;
        cnt+=mp[remove];
        mp[presum]+=1;
       }
       return cnt;
    }
};

// Brute Force 
//  int count=0;
//         for(int i=0;i<nums.size();i++){
//             int sum=0;
//             for(int j=i;j<nums.size();j++){
//                 sum+=nums[j];
//                 if(sum==k) ++count;
//             }
//         }
//         return count;