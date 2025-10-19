class Solution {
public:
    int mySqrt(int x) {
        int l = 0, h = x, mid = 0;
        int res = 0;
        while (l <= h) {
            mid = l + (h - l) / 2;
            if ((long long)mid * mid > x)
                h = mid - 1;
            else if ((long long)mid * mid < x) {
                res = mid;
                l = mid + 1;
            } else
                return mid;
        }
        return res;
    }
};