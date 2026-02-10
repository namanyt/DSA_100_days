#include <stdio.h>
#include <string.h>

/* Reverse a string and print the mirrored result. */
int main() {
    char s[2000]; /* input string buffer */
    if (scanf("%1999s", s) != 1) {
        return 0; /* no valid input */
    }

    int n = (int)strlen(s); /* string length */
    for (int i = n - 1; i >= 0; i--) {
        putchar(s[i]); /* print in reverse order */
    }
    return 0; /* success */
}
