class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        map<int, int>mp;
        for (int i = 0;i < nums.size();i++) {
            mp[nums[i]]++;
        }
        auto it = mp.begin();
        int ans = 1, maxi = 1;
        for (;it != mp.end();it++) {
            auto next_it = next(it);
            if (next_it == mp.end()) break;
            if ((next_it->first) -it->first == 1) {
                ans++;
            }
            else {
                ans = 1;
            }
            maxi = max(ans, maxi);
        }
        return maxi;
    }   
};


//   int n=nums.size();
//        int longest=1;
//        if(n==0) return 0;
//        unordered_set<int>st;
//        for(int i=0;i<n;i++){
//         st.insert(nums[i]);
//        }
//        for(auto it:nums){
//         if(st.find(it-1)==st.end()) {  // didn't found number less than number by one 
//             int x=it;
//             int cnt=1;
//             while(st.find(x+1)!=st.end()){
//                 x++;
//                 cnt++;
//             }
//         longest=max(longest,cnt);
//         }
//        }
//        return longest;