#include <stdio.h>

/* Count subarrays with sum zero using prefix sums and a simple map. */
int main() {
    int n; /* array size */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    long long arr[5000]; /* array storage */
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]); /* read each element */
    }

    long long sums[10000]; /* stored prefix sums */
    long long freq[10000]; /* frequencies of prefix sums */
    int size = 0;          /* number of unique sums stored */

    long long prefix = 0; /* running prefix sum */
    long long count = 0;  /* number of zero-sum subarrays */

    /* prefix sum 0 occurs once before any elements */
    sums[size] = 0;
    freq[size] = 1;
    size++;

    for (int i = 0; i < n; i++) {
        prefix += arr[i]; /* update prefix sum */
        int found = -1;
        for (int j = 0; j < size; j++) {
            if (sums[j] == prefix) {
                found = j; /* existing sum found */
                break;
            }
        }
        if (found != -1) {
            count += freq[found]; /* add previous occurrences */
            freq[found]++; /* update frequency */
        } else {
            sums[size] = prefix; /* store new sum */
            freq[size] = 1;      /* initialize frequency */
            size++;
        }
    }

    printf("%lld", count); /* output result */
    return 0; /* success */
}
