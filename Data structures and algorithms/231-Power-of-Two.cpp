class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(n&(n-1)) return false;   // 1000 and 0111 ==> 0000 
        return true;
    }
};