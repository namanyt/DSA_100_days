#include <stdio.h>
#include <string.h>

/* Find the winner of an election by votes with lexicographic tie-break. */
int main() {
    int n; /* number of votes */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    char names[1000][100];
    int counts[1000];
    int size = 0; /* number of unique candidates */

    for (int i = 0; i < n; i++) {
        char name[100];
        scanf("%99s", name);
        int idx = -1;
        for (int j = 0; j < size; j++) {
            if (strcmp(names[j], name) == 0) {
                idx = j;
                break;
            }
        }
        if (idx == -1) {
            strcpy(names[size], name); /* new candidate */
            counts[size] = 1;
            size++;
        } else {
            counts[idx]++; /* increment vote */
        }
    }

    int best = 0;
    for (int i = 1; i < size; i++) {
        if (counts[i] > counts[best]) {
            best = i;
        } else if (counts[i] == counts[best] && strcmp(names[i], names[best]) < 0) {
            best = i; /* lexicographically smaller on tie */
        }
    }

    printf("%s %d", names[best], counts[best]);
    return 0; /* success */
}
