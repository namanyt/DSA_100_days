#include <stdio.h>

/* Count how many times a key appears. */
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
    scanf("%d", &key); /* key to count */

    int count = 0; /* frequency */
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            count++;
        }
    }

    printf("%d", count); /* output count */
    return 0; /* success */
}
