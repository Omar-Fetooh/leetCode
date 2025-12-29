class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        vector<vector<int>>ans;
        int i=0;
        dfs(subset,i,ans,nums);
        return ans;
    };

    void dfs(vector<int>&subset,int i, vector<vector<int>>&ans,vector<int>&nums){
        if(i>=nums.size()){
            ans.push_back(subset);
            return ;
        }
        subset.push_back(nums[i]);
        dfs(subset,i+1,ans,nums);
        subset.pop_back();
        dfs(subset,i+1,ans,nums);
    }
};