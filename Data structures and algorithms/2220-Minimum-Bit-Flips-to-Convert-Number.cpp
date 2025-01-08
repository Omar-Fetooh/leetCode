class Solution {
public:
   int minBitFlips(int start, int goal) {
    int ans = 0;
    int temp = start ^ goal;
    while (temp > 0) {
        ans += (temp & 1);  // bt4of first bit 0 or 1 
        temp = temp >> 1;  
    }
    return ans;
}
};