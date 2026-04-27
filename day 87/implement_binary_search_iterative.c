#include <stdio.h>

/* Iterative binary search in a sorted array. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    if (scanf("%d", &key) != 1) {
        return 0; /* no valid input */
    }

    int l = 0, r = n - 1;
    int idx = -1; /* not found */
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m] == key) {
            idx = m;
            break;
        }
        if (arr[m] < key) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    printf("%d", idx);
    return 0; /* success */
}
