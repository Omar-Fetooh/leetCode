class Solution {
public:
    int countPrimes(int n) {
     vector<bool>isPrime(n + 1, true);

    isPrime[0] = isPrime[1]=0;
    for (long long i = 2;i * i <= n;i++) {
        if (isPrime[i]) {
            for (int j = i * 2;j <= n;j += i) {
                isPrime[j] = 0;
            }
        }
    }
    int cnt = 0;
    for (int i = 0;i < n + 1;i++) if (isPrime[i]&&i<n)++cnt;
    return cnt;
    }
};