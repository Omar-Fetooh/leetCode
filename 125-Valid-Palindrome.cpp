class Solution {
public:
    bool isPalindrome(string s) {
        string newS;
        for(int i=0;i<s.size();i++){
            if(s[i]>=65&&s[i]<=90) s[i]=s[i]+32;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]>=97&&s[i]<=122||s[i]>=48&&s[i]<=57) newS+=s[i];
        }
        string temp=newS;
        reverse(temp.begin(),temp.end());
        if(temp==newS) return true;
        return false;
    }
};