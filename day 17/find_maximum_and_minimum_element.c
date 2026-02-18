#include <stdio.h>

/* Find maximum and minimum elements in an array. */
int main() {
    int n; /* array size */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int x; /* current value */
    scanf("%d", &x); /* read first element */
    int minv = x, maxv = x; /* initialize min and max */

    for (int i = 1; i < n; i++) {
        scanf("%d", &x); /* read next element */
        if (x < minv) {
            minv = x; /* update min */
        }
        if (x > maxv) {
            maxv = x; /* update max */
        }
    }

    printf("Max: %d\nMin: %d", maxv, minv); /* output results */
    return 0; /* success */
}
