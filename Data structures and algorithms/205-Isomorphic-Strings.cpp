class Solution {
public:
    bool isIsomorphic(string s, string t) {
     map<char, char>mp;
        for (int i = 0;i < s.size();i++) {
            if (mp.find(s[i]) != mp.end()) { // found 
                s[i] = mp[s[i]];
            }
            else { // not found
                for (auto pr : mp) {
                    if (t[i] == pr.second) return false;
                }
                mp[s[i]] = t[i];
                s[i] = mp[s[i]];
            }
        }
        return s == t;   
    }
};