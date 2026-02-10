#include <stdio.h>

/* Compute a^b using recursion (no pow()). */
static long long power(long long a, long long b) {
    if (b == 0) {
        return 1; /* base case: a^0 = 1 */
    }
    return a * power(a, b - 1); /* multiply a, b times */
}

int main() {
    long long a, b; /* base and exponent */
    if (scanf("%lld %lld", &a, &b) != 2) {
        return 0; /* no valid input */
    }

    printf("%lld", power(a, b)); /* output result */
    return 0; /* success */
}
