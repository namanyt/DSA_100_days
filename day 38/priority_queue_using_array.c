#include <stdio.h>
#include <string.h>

/* Implement a min-priority queue using an unsorted array. */
int main() {
    int N; /* number of operations */
    if (scanf("%d", &N) != 1) {
        return 0; /* no valid input */
    }

    int arr[10000];
    int size = 0; /* current size */

    for (int i = 0; i < N; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            arr[size++] = x; /* insert at end */
        } else if (strcmp(op, "delete") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                int min_idx = 0;
                for (int j = 1; j < size; j++) {
                    if (arr[j] < arr[min_idx]) {
                        min_idx = j; /* find minimum */
                    }
                }
                printf("%d\n", arr[min_idx]); /* output min */
                arr[min_idx] = arr[size - 1]; /* remove by swap */
                size--;
            }
        } else if (strcmp(op, "peek") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                int min_idx = 0;
                for (int j = 1; j < size; j++) {
                    if (arr[j] < arr[min_idx]) {
                        min_idx = j;
                    }
                }
                printf("%d\n", arr[min_idx]); /* output min */
            }
        }
    }
    return 0; /* success */
}
