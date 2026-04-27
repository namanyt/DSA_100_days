#include <stdio.h>
#include <stdlib.h>

/* Compare integers for qsort. */
static int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

/* Check if k cows can be placed with at least dist apart. */
static int can_place(int arr[], int n, int k, int dist) {
    int count = 1;
    int last = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] - last >= dist) {
            count++;
            last = arr[i];
            if (count >= k) {
                return 1;
            }
        }
    }
    return 0;
}

/* Aggressive cows: maximize minimum distance using binary search. */
int main() {
    int n, k; /* number of stalls and cows */
    if (scanf("%d %d", &n, &k) != 2) {
        return 0; /* no valid input */
    }

    int arr[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp_int); /* sort stall positions */

    int l = 0;
    int r = arr[n - 1] - arr[0];
    int ans = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (can_place(arr, n, k, m)) {
            ans = m; /* feasible distance */
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    printf("%d", ans);
    return 0; /* success */
}
