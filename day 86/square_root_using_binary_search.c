#include <stdio.h>

/* Compute integer square root using binary search. */
int main() {
    long long n; /* input value */
    if (scanf("%lld", &n) != 1) {
        return 0; /* no valid input */
    }

    long long l = 0, r = n, ans = 0;
    while (l <= r) {
        long long m = (l + r) / 2;
        if (m * m <= n) {
            ans = m; /* m is a candidate */
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    printf("%lld", ans);
    return 0; /* success */
}
