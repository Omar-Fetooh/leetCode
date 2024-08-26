class Solution {
public:
   static bool preceed(pair<int, int>&a, pair<int, int>&b) {
            return a.second > b.second;
    }
    string frequencySort(string s) {
         string ans;
        vector<pair<int,int>>v(125,{0,0});
         for (int i = 0; i < 125; i++) {
        v[i].first = i;  
        v[i].second = 0;
        }
        for (int i = 0;i < s.size();i++) {
            v[(int)s[i]].second++;
        }
        sort(v.begin(), v.end(), preceed);
        for (int i = 0;i < v.size();i++) {
            while (v[i].second--) {
                ans += char(v[i].first);
            }
        }
        return ans;
    }
};