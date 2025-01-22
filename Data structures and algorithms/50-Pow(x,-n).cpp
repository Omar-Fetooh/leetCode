class Solution {
public:
    double myPow(double x, long long int n) {
        double ans=1;
        bool flag = true;
        if (n == 0) return 1;
        if (n < 0)
        {
            flag = false;
            n = abs(n) ;
        }
    
        while (n) {
            if (n % 2 == 1) {
                ans = ans * x;
                n = n - 1;
            }
            else {
                n = n / 2;
                x = x * x;
            }
        }

        if (!flag) return 1 / ans;
        return ans;
    }
};