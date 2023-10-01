class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;

        long long quotient = 0;

        while (ldividend >= ldivisor) {
            long long temp = ldivisor, multiple = 1;
            while (ldividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            ldividend -= temp;
            quotient += multiple;
        }

        return sign * quotient;
    }
};