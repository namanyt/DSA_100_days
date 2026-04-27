#include <stdio.h>

/* Compute product of array except self without division. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    long long arr[2000];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    long long left[2000];
    long long right[2000];

    left[0] = 1;
    for (int i = 1; i < n; i++) {
        left[i] = left[i - 1] * arr[i - 1];
    }

    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        right[i] = right[i + 1] * arr[i + 1];
    }

    for (int i = 0; i < n; i++) {
        long long prod = left[i] * right[i];
        if (i) {
            printf(" ");
        }
        printf("%lld", prod);
    }

    return 0; /* success */
}
