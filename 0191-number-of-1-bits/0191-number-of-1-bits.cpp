class Solution {
public:
    int hammingWeight(int n) {
        // string bin;
        int cnt = 0;
        while (n > 0) {
            int res = n % 2;
            if (res == 1)
                cnt++;
            n /= 2;
        }
        return cnt;
    }
};