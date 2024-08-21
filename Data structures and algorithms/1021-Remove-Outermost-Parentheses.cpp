class Solution {
public:
    string removeOuterParentheses(string s) {
        string newString="";
        int sum=0;
        for(int i=0;i<s.size();i++){
            if(sum==0&&s[i]=='('){
                ++sum;
                continue;
            }
            else if(sum==1&&s[i]==')'){
                --sum;
                continue;
            }
            else if(s[i]=='('){
                ++sum;
                newString+=s[i];
            }
            else{
                 --sum;
                 newString+=s[i];
            }
        }
        return newString;
    }
};