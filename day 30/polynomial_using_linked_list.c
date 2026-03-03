#include <stdio.h>

/* Print a polynomial from coefficient-exponent pairs. */
int main() {
    int n; /* number of terms */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int coeff, exp; /* term components */
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp); /* read term */
        if (i) {
            printf(" + ");
        }
        if (exp == 0) {
            printf("%d", coeff); /* constant term */
        } else if (exp == 1) {
            printf("%dx", coeff); /* linear term */
        } else {
            printf("%dx^%d", coeff, exp); /* higher degree term */
        }
    }
    return 0; /* success */
}
