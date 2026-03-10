#include <stdio.h>

/* Print stack elements from top to bottom (linked-list conceptual). */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000]; /* simulate stack storage */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); /* push order */
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1) {
            printf(" ");
        }
        printf("%d", arr[i]); /* top to bottom */
    }
    return 0; /* success */
}
