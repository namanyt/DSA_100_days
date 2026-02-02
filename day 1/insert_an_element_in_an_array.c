#include <stdio.h>

/* Insert an element at a given 1-based position in an array. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000]; /* array storage (room for n+1) */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); /* read each element */
    }

    int pos, x; /* insertion position and value */
    scanf("%d", &pos); /* read 1-based position */
    scanf("%d", &x);   /* read value to insert */

    int idx = pos - 1; /* convert to 0-based index */
    for (int i = n; i > idx; i--) {
        arr[i] = arr[i - 1]; /* shift right to make space */
    }
    arr[idx] = x; /* insert element */

    for (int i = 0; i < n + 1; i++) {
        if (i) {
            printf(" "); /* space between elements */
        }
        printf("%d", arr[i]); /* print updated array */
    }
    return 0; /* success */
}
