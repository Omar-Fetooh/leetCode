class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long int sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++) sum+=weights[i];
        long long low=*max_element(weights.begin(), weights.end()),high=sum;
        while(low<=high){
            long long mid=(low+high)/2;
            int tempo=0,counter=1;
            for(int i=0;i<n&&counter<=days;i++){
                if(tempo+weights[i]<=mid){
                    tempo+=weights[i];
                }
                else{
                    --i;
                    ++counter;
                    tempo=0;
                }
            }
            if(counter<=days) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};