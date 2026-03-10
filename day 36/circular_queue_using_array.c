#include <stdio.h>

/* Simulate circular queue rotation by m and print order. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000]; /* queue storage */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); /* read elements */
    }

    int m; /* number of dequeues */
    scanf("%d", &m);
    if (n == 0) {
        return 0; /* nothing to rotate */
    }

    m %= n; /* rotation amount */
    for (int i = 0; i < n; i++) {
        int idx = (m + i) % n; /* front after m dequeues */
        if (i) {
            printf(" ");
        }
        printf("%d", arr[idx]);
    }
    return 0; /* success */
}
