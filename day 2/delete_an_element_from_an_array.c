#include <stdio.h>

/* Delete an element at a given 1-based position in an array. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000]; /* array storage */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); /* read each element */
    }

    int pos; /* 1-based position to delete */
    scanf("%d", &pos);

    int idx = pos - 1; /* convert to 0-based index */
    for (int i = idx; i < n - 1; i++) {
        arr[i] = arr[i + 1]; /* shift left to fill gap */
    }

    for (int i = 0; i < n - 1; i++) {
        if (i) {
            printf(" "); /* space between elements */
        }
        printf("%d", arr[i]); /* print updated array */
    }
    return 0; /* success */
}
