#include <stdio.h>
#include <string.h>

/* Hash table with chaining (arrays as lists). */
int main() {
    int m, n; /* table size and number of operations */
    if (scanf("%d", &m) != 1) {
        return 0; /* no valid input */
    }
    scanf("%d", &n);

    int table[200][200];
    int size[200] = {0}; /* size of each chain */

    for (int i = 0; i < n; i++) {
        char op[20];
        int x;
        scanf("%s %d", op, &x);

        int idx = ((x % m) + m) % m; /* hash index */
        if (strcmp(op, "INSERT") == 0) {
            table[idx][size[idx]++] = x; /* insert at end of chain */
        } else if (strcmp(op, "SEARCH") == 0) {
            int found = 0;
            for (int j = 0; j < size[idx]; j++) {
                if (table[idx][j] == x) {
                    found = 1;
                    break;
                }
            }
            printf(found ? "FOUND\n" : "NOT FOUND\n");
        } else if (strcmp(op, "DELETE") == 0) {
            for (int j = 0; j < size[idx]; j++) {
                if (table[idx][j] == x) {
                    for (int k = j; k < size[idx] - 1; k++) {
                        table[idx][k] = table[idx][k + 1];
                    }
                    size[idx]--;
                    break;
                }
            }
        }
    }

    return 0; /* success */
}
