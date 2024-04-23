class Solution {
public:
    void reverse_str(string& str){
        string res;
        for(int i=0;i<str.length();i++){
            res+=str[str.length()-i-1];
        }
        str=res;
    }
    int reverse(int x) {
       long long  rev=0;
       while(x!=0){
        int lastDigit=x%10;
        rev=rev*10+lastDigit;
        x/=10;
       }
       if(rev>INT_MAX||rev<INT_MIN) return 0;
       return (int)rev;
    }
};