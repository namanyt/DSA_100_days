#include <stdio.h>

/* Linear search with comparison counting. */
int main() {
    int n; /* size of array */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000]; /* array storage */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); /* read each element */
    }

    int k; /* key to search */
    scanf("%d", &k);

    int comparisons = 0; /* comparison counter */
    int found_index = -1; /* index of key if found */

    for (int i = 0; i < n; i++) {
        comparisons++; /* compare current element with key */
        if (arr[i] == k) {
            found_index = i; /* record index */
            break; /* stop after first match */
        }
    }

    if (found_index != -1) {
        printf("Found at index %d\n", found_index); /* print index */
    } else {
        printf("Not Found\n"); /* key not present */
    }
    printf("Comparisons = %d", comparisons); /* print comparison count */
    return 0; /* success */
}
