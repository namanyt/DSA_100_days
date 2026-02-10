#include <stdio.h>
#include <string.h>

/* Check whether a string is a palindrome using two pointers. */
int main() {
    char s[2000]; /* input string buffer */
    if (scanf("%1999s", s) != 1) {
        return 0; /* no valid input */
    }

    int l = 0;                    /* left pointer */
    int r = (int)strlen(s) - 1;   /* right pointer */
    int ok = 1;                   /* palindrome flag */

    while (l < r) {
        if (s[l] != s[r]) { /* mismatch */
            ok = 0;
            break;
        }
        l++;
        r--;
    }

    printf(ok ? "YES" : "NO"); /* print result */
    return 0; /* success */
}
