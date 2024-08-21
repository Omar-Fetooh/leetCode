class Solution {
public:
    bool isOdd(int n){
         return n%2==1;
    }
    string largestOddNumber(string num) {
        int maxi=0;
        for(int i=num.size()-1;i>=0;i--){
            if(isOdd(int(num[i]))) return num.substr(0,i+1);
        }
        return "";
    }
};