#include <stdio.h>
#include <string.h>

/* Process deque operations using a fixed array. */
int main() {
    int N; /* number of operations */
    if (scanf("%d", &N) != 1) {
        return 0; /* no valid input */
    }

    int dq[10000];
    int front = 5000, rear = 4999; /* empty deque */

    for (int i = 0; i < N; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "pushFront") == 0) {
            int x;
            scanf("%d", &x);
            dq[--front] = x; /* insert at front */
        } else if (strcmp(op, "pushRear") == 0) {
            int x;
            scanf("%d", &x);
            dq[++rear] = x; /* insert at rear */
        } else if (strcmp(op, "popFront") == 0) {
            if (front > rear) {
                printf("-1\n");
            } else {
                printf("%d\n", dq[front++]); /* remove front */
            }
        } else if (strcmp(op, "popRear") == 0) {
            if (front > rear) {
                printf("-1\n");
            } else {
                printf("%d\n", dq[rear--]); /* remove rear */
            }
        } else if (strcmp(op, "peekFront") == 0) {
            if (front > rear) {
                printf("-1\n");
            } else {
                printf("%d\n", dq[front]); /* view front */
            }
        } else if (strcmp(op, "peekRear") == 0) {
            if (front > rear) {
                printf("-1\n");
            } else {
                printf("%d\n", dq[rear]); /* view rear */
            }
        }
    }
    return 0; /* success */
}
