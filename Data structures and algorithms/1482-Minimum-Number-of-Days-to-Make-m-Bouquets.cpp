class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((double)m*k>n)return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int bouquetsDone=0,tempk=k;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    tempk--;
                    if(tempk==0){
                        tempk=k;
                        ++bouquetsDone;
                    }
                }
                else tempk=k;
            }
            if(bouquetsDone>=m) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};