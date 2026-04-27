#include <stdio.h>

/* Check if b is in arithmetic progression starting at a with diff c. */
int main() {
    long long a, b, c;
    if (scanf("%lld", &a) != 1) {
        return 0; /* no valid input */
    }
    if (scanf("%lld", &b) != 1) {
        return 0;
    }
    if (scanf("%lld", &c) != 1) {
        return 0;
    }

    if (c == 0) {
        printf(b == a ? "1" : "0");
        return 0;
    }

    long long diff = b - a;
    if (diff % c == 0 && diff / c >= 0) {
        printf("1");
    } else {
        printf("0");
    }

    return 0; /* success */
}
