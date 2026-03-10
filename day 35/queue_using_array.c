#include <stdio.h>

/* Read queue elements and print them in order. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x); /* enqueue order */
        if (i) {
            printf(" ");
        }
        printf("%d", x); /* output queue */
    }
    return 0; /* success */
}
