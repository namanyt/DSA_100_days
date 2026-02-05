#include <stdio.h>

/* Reverse an array in place using two pointers. */
int main() {
    int n; /* array size */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000]; /* array storage */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); /* read each element */
    }

    int l = 0, r = n - 1; /* two pointers */
    while (l < r) {
        int tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp; /* swap ends */
        l++;
        r--;
    }

    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" "); /* space between elements */
        }
        printf("%d", arr[i]); /* print reversed array */
    }
    return 0; /* success */
}
