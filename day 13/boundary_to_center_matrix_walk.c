#include <stdio.h>

/* Print matrix elements in clockwise spiral order. */
int main() {
    int r, c; /* rows and columns */
    if (scanf("%d %d", &r, &c) != 2) {
        return 0; /* no valid input */
    }

    int a[50][50]; /* matrix */
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]); /* read elements */
        }
    }

    int top = 0, bottom = r - 1, left = 0, right = c - 1; /* boundaries */
    int first = 1; /* spacing flag */

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            if (!first) {
                printf(" ");
            }
            printf("%d", a[top][j]); /* top row */
            first = 0;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            if (!first) {
                printf(" ");
            }
            printf("%d", a[i][right]); /* right column */
            first = 0;
        }
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                if (!first) {
                    printf(" ");
                }
                printf("%d", a[bottom][j]); /* bottom row */
                first = 0;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                if (!first) {
                    printf(" ");
                }
                printf("%d", a[i][left]); /* left column */
                first = 0;
            }
            left++;
        }
    }
    return 0; /* success */
}
