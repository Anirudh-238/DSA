#include <climits>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Use long long to handle absolute value of INT_MIN
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);
        long long quotient = 0;

        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long count = 1;

            // Double the divisor until it's larger than the dividend
            // This is essentially checking: divisor * 2^x
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                count <<= 1;
            }

            absDividend -= tempDivisor;
            quotient += count;
        }

        return isNegative ? -quotient : quotient;
    }
};