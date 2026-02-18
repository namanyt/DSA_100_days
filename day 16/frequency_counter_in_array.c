#include <stdio.h>

/* Count frequencies of each distinct element in the array. */
int main() {
    int n; /* array size */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000]; /* array storage */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); /* read each element */
    }

    int used[2000] = {0}; /* mark processed indices */
    int first = 1;        /* spacing flag */

    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue; /* already counted */
        }
        int count = 1; /* count occurrences of arr[i] */
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                used[j] = 1; /* mark duplicate */
                count++;
            }
        }
        if (!first) {
            printf(" ");
        }
        printf("%d:%d", arr[i], count); /* print element:count */
        first = 0;
    }
    return 0; /* success */
}
