#include <stdio.h>
#include <string.h>

/* Print the first non-repeating character in a string. */
int main() {
    char s[2000];
    if (scanf("%1999s", s) != 1) {
        return 0; /* no valid input */
    }

    int freq[256] = {0};
    for (int i = 0; s[i]; i++) {
        freq[(unsigned char)s[i]]++; /* count frequency */
    }

    for (int i = 0; s[i]; i++) {
        if (freq[(unsigned char)s[i]] == 1) {
            printf("%c", s[i]);
            return 0;
        }
    }

    printf("$"); /* no non-repeating character */
    return 0; /* success */
}
