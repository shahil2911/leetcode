class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modularExponentiation(long long x, long long n) {
        if (n == 0) return 1;
        x %= MOD;

        long long halfPower = modularExponentiation(x, n / 2);
        long long result = (halfPower * halfPower) % MOD;

        if (n % 2 == 1) {
            result = (result * x) % MOD;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        if (n == 1) return 5;
        if (n == 2) return 20;

        long long temp = n / 2;
        long long res;

        if (n % 2 == 0) {
            res = (modularExponentiation(5, temp) * modularExponentiation(4, temp)) % MOD;
        } else {
            res = (modularExponentiation(5, temp + 1) * modularExponentiation(4, temp)) % MOD;
        }

        return static_cast<int>(res);
    }
};
