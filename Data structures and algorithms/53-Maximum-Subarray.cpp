class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;
    }
};

// INTIAL SOLUTION 
// brute force O(n^2)
    //     int n=nums.size();
    //     int maxi=-100000,sum=0;
    //     for(int i=0;i<n;i++){
    //         sum=0;
    //         for(int j=i;j<n;j++){
    //         sum+=nums[j];
    //         maxi=max(maxi,sum);
    //         }
    //     }
    // return maxi;