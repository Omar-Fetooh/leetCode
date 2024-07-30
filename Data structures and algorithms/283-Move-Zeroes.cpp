class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0,zeroCnt=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                ++zeroCnt;
            }
            else if(nums[j]!=0){
                nums[i]=nums[j];
                ++i;
            }
        }
        while(zeroCnt--){
            nums[i]=0;
            ++i;
        }
    }
};