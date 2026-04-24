#include <stdio.h>
#include <string.h>

/* Hash table with linear probing. */
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

    int count = 0; /* number of occupied slots */
    for (int i = 0; i < n; i++) {
        char op[20];
        int x;
        scanf("%s %d", op, &x);

        if (strcmp(op, "INSERT") == 0) {
            if (count == m) {
                printf("HASH TABLE FULL\n");
                continue;
            }
            int idx = ((x % m) + m) % m; /* initial hash */
            while (table[idx] != -1 && table[idx] != x) {
                idx = (idx + 1) % m; /* linear probing */
            }
            if (table[idx] == -1) {
                table[idx] = x;
                count++;
            }
        } else if (strcmp(op, "SEARCH") == 0) {
            int idx = ((x % m) + m) % m; /* initial hash */
            int steps = 0;
            int found = 0;
            while (steps < m && table[idx] != -1) {
                if (table[idx] == x) {
                    found = 1;
                    break;
                }
                idx = (idx + 1) % m; /* probe next */
                steps++;
            }
            printf(found ? "FOUND\n" : "NOT FOUND\n");
        }
    }

    return 0; /* success */
}
