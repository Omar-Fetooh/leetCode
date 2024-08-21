class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>v;
        int i=0;
        int curr=1;
        for(;i<arr.size();){
            if (arr[i] ==curr) {
             curr++;
             ++i;
            }
            else {
                v.push_back(curr);
                ++curr;
            }
        }
        while(k>v.size()){
            v.push_back(curr++);
        }
        return v[k-1];
    }
};