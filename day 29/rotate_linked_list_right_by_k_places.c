#include <stdio.h>

/* Reverse a segment of an array. */
static void reverse(int arr[], int l, int r) {
    while (l < r) {
        int t = arr[l];
        arr[l] = arr[r];
        arr[r] = t;
        l++;
        r--;
    }
}

/* Rotate list to the right by k places and print. */
int main() {
    int n; /* number of nodes */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000]; /* list values */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); /* read values */
    }

    int k; /* rotation amount */
    scanf("%d", &k);
    if (n == 0) {
        return 0; /* nothing to rotate */
    }

    k %= n; /* reduce k */
    reverse(arr, 0, n - 1); /* reverse all */
    reverse(arr, 0, k - 1); /* reverse first k */
    reverse(arr, k, n - 1); /* reverse remaining */

    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", arr[i]); /* output rotated list */
    }
    return 0; /* success */
}
