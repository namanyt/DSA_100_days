#include <stdio.h>

/* Reverse a segment of an array. */
static void reverse(int arr[], int l, int r) {
    while (l < r) {
        int t = arr[l];
        arr[l] = arr[r];
        arr[r] = t; /* swap ends */
        l++;
        r--;
    }
}

/* Rotate array to the right by k positions. */
int main() {
    int n; /* array size */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000]; /* array storage */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); /* read each element */
    }

    int k; /* rotation amount */
    scanf("%d", &k);
    if (n == 0) {
        return 0; /* nothing to rotate */
    }

    k %= n; /* reduce k within array bounds */
    reverse(arr, 0, n - 1);     /* reverse whole array */
    reverse(arr, 0, k - 1);     /* reverse first k elements */
    reverse(arr, k, n - 1);     /* reverse remaining elements */

    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", arr[i]); /* print rotated array */
    }
    return 0; /* success */
}
