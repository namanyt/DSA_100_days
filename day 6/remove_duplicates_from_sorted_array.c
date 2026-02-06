#include <stdio.h>

/* Remove duplicates from a sorted array and print unique elements. */
int main() {
    int n; /* array size */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000]; /* array storage */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); /* read each element */
    }
    if (n == 0) {
        return 0; /* nothing to output */
    }

    int write = 0; /* index for unique elements */
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[write]) {
            write++;
            arr[write] = arr[i]; /* keep unique element */
        }
    }

    for (int i = 0; i <= write; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", arr[i]); /* print unique elements */
    }
    return 0; /* success */
}
