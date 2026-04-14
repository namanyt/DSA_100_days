#include <stdio.h>
#include <string.h>

/* Hash table with quadratic probing. */
int main() {
    int m, n; /* table size and number of operations */
    if (scanf("%d", &m) != 1) {
        return 0; /* no valid input */
    }
    scanf("%d", &n);

    int table[1000];
    for (int i = 0; i < m; i++) {
        table[i] = -1; /* empty slot */
    }

    for (int i = 0; i < n; i++) {
        char op[20];
        int x;
        scanf("%s %d", op, &x);

        if (strcmp(op, "INSERT") == 0) {
            int h = ((x % m) + m) % m; /* initial hash */
            int inserted = 0;
            for (int j = 0; j < m; j++) {
                int idx = (h + j * j) % m; /* quadratic probe */
                if (table[idx] == -1 || table[idx] == x) {
                    table[idx] = x;
                    inserted = 1;
                    break;
                }
            }
            if (!inserted) {
                printf("HASH TABLE FULL\n");
            }
        } else if (strcmp(op, "SEARCH") == 0) {
            int h = ((x % m) + m) % m; /* initial hash */
            int found = 0;
            for (int j = 0; j < m; j++) {
                int idx = (h + j * j) % m;
                if (table[idx] == -1) {
                    break; /* empty slot stops search */
                }
                if (table[idx] == x) {
                    found = 1;
                    break;
                }
            }
            printf(found ? "FOUND\n" : "NOT FOUND\n");
        }
    }

    return 0; /* success */
}
