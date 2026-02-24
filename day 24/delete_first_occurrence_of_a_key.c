#include <stdio.h>

/* Delete the first occurrence of a key and print the list. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000]; /* list values */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); /* read elements */
    }

    int key;
    scanf("%d", &key); /* key to delete */

    int idx = -1; /* index of first occurrence */
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            idx = i;
            break;
        }
    }

    if (idx != -1) {
        for (int i = idx; i < n - 1; i++) {
            arr[i] = arr[i + 1]; /* shift left */
        }
        n--; /* reduce size */
    }

    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", arr[i]); /* print list */
    }
    return 0; /* success */
}
