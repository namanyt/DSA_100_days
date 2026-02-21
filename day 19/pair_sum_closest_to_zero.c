#include <stdio.h>
#include <stdlib.h>

/* Compare function for qsort (ascending). */
static int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

/* Find pair with sum closest to zero. */
int main() {
    int n; /* array size */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[3000]; /* array storage */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); /* read each element */
    }

    qsort(arr, n, sizeof(int), cmp_int); /* sort array */

    int l = 0, r = n - 1; /* two pointers */
    int best_l = l, best_r = r; /* best pair indices */
    long best_sum = (long)arr[l] + arr[r]; /* best sum */

    while (l < r) {
        long sum = (long)arr[l] + arr[r];
        if (llabs(sum) < llabs(best_sum)) {
            best_sum = sum; /* update best sum */
            best_l = l;
            best_r = r;
        }
        if (sum < 0) {
            l++; /* need larger sum */
        } else {
            r--; /* need smaller sum */
        }
    }

    printf("%d %d", arr[best_l], arr[best_r]); /* output pair */
    return 0; /* success */
}
