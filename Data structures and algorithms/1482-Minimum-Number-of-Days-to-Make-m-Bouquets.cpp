class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((double)m*k>n)return -1;
        unordered_set<int>unique_elements(bloomDay.begin(),bloomDay.end());
        vector<int>searchSpace;
        for(auto element:unique_elements){
            searchSpace.push_back(element);
        }
        sort(searchSpace.begin(),searchSpace.end());
        int low=0,high=searchSpace.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int bouquetsDone=0,tempk=k;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=searchSpace[mid]){
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
        return searchSpace[low];
    }
};