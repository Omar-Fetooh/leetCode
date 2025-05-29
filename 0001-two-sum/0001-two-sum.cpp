class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      //  bool founded=false;
        vector<int>sol;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(target-nums[i]))
            {
                sol.push_back(i);
                auto it=mp.find(target-nums[i]);
                sol.push_back(it->second);
                break;
            }
            else{
                mp.insert({nums[i],i});
            }
        }
        return sol;}
};