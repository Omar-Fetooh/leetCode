class Solution {
public:
    bool isPalindrome(int x) {
    int temp=x;
    long long rev=0;
    while(temp>0){
        int last_digit=temp%10;
        rev=rev*10+last_digit;
        temp/=10;
    }
    if(rev>INT_MAX||rev<INT_MIN) return false;
    if(rev==x) return true;
    else return false;
    }
};