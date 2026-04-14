#include <stdio.h>
#include <string.h>

/* Print the first repeated character in a string. */
int main() {
    char s[2000];
    if (scanf("%1999s", s) != 1) {
        return 0; /* no valid input */
    }

    int seen[256] = {0};
    for (int i = 0; s[i]; i++) {
        unsigned char c = (unsigned char)s[i];
        if (seen[c]) {
            printf("%c", c);
            return 0;
        }
        seen[c] = 1;
    }

    printf("-1"); /* no repeated character */
    return 0; /* success */
}
