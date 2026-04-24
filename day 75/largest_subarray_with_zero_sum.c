#include <stdio.h>

/* Find the length of the largest subarray with sum zero. */
int main() {
    long long vals[5000];
    int n = 0;

    /* Read all integers (some inputs may not give explicit n). */
    while (scanf("%lld", &vals[n]) == 1) {
        n++;
    }
    if (n == 0) {
        return 0; /* no input */
    }

    int start = 0;
    if (n >= 2 && vals[0] == n - 1) {
        start = 1; /* treat first value as length */
    }

    int len = n - start;
    long long prefix[6000];
    int first_idx[6000];
    int size = 0;

    long long sum = 0;
    int best = 0;

    prefix[size] = 0;
    first_idx[size] = -1;
    size++;

    for (int i = 0; i < len; i++) {
        sum += vals[start + i];
        int found = -1;
        for (int j = 0; j < size; j++) {
            if (prefix[j] == sum) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            int cur = i - first_idx[found];
            if (cur > best) {
                best = cur; /* update best length */
            }
        } else {
            prefix[size] = sum; /* store first occurrence */
            first_idx[size] = i;
            size++;
        }
    }

    printf("%d", best);
    return 0; /* success */
}
