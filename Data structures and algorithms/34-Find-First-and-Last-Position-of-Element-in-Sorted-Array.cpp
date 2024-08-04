class Solution {
public:
// striver code 
    int firstOcc(vector<int>& nums, int n,int target){
        int low=0,high=n-1;
        int first=-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return first;
    }
        int lastOcc(vector<int>& nums, int n,int target){
        int low=0,high=n-1;
        int last=-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=firstOcc(nums,n,target);
        if(first==-1) return {-1,-1};
        int last=lastOcc(nums,n,target);
        return {first,last};
    }
};

// my accpeted code  11 ms
// if(nums.size()==1){
//             vector<int>finals;
//             if(target==nums[0]) {
//                 finals.push_back(0);
//                 finals.push_back(0);
//             }
//             else {
//                   finals.push_back(-1);
//                   finals.push_back(-1);
//             }
//             return finals;
//         }
//         int low=0,high=nums.size()-1;
//         vector<int>ans;
//         bool flag=false;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(nums[mid]<target)low=mid+1;
//             else if(nums[mid]>target)high=mid-1;
//             else{
//                 flag=true;
//                 int i=0,j=0;
//                 while(mid-i>=0&&nums[mid-i]==target) ++i;
//                 while(mid+j<=nums.size()-1&&nums[mid+j]==target)++j;
//                 ans.push_back(mid-i+1);
//                 ans.push_back(mid+j-1);
//                 break;
//             }
//         }
//          if(!flag){
//             ans.push_back(-1);  
//             ans.push_back(-1);
//             } 
//         return ans;