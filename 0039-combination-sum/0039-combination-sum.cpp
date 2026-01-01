class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>cur;
        backtrack(candidates,target,cur,0);

        return res;
    }
    void backtrack(vector<int>&candidates,int target,vector<int>&cur,int i ){
        if(target==0){
            res.push_back(cur);
            return ;

        }
        if(target<0||i>=candidates.size()) return;
        cur.push_back(candidates[i]);
        backtrack(candidates,target-candidates[i],cur,i);
        cur.pop_back();
        backtrack(candidates,target,cur,i+1);
    }
};