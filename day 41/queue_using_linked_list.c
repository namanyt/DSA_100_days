#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Node structure for linked-list queue. */
typedef struct Node {
    int val;
    struct Node *next;
} Node;

/* Process enqueue and dequeue operations. */
int main() {
    int n; /* number of operations */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    Node *front = NULL; /* queue front */
    Node *rear = NULL;  /* queue rear */

    for (int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            int x;
            scanf("%d", &x);

            Node *node = (Node *)malloc(sizeof(Node));
            node->val = x;
            node->next = NULL;

            if (!rear) {
                front = rear = node; /* first element */
            } else {
                rear->next = node; /* append to rear */
                rear = node;
            }
        } else if (strcmp(op, "dequeue") == 0) {
            if (!front) {
                printf("-1\n"); /* empty queue */
            } else {
                Node *tmp = front;
                printf("%d\n", tmp->val); /* output front */
                front = front->next;
                if (!front) {
                    rear = NULL; /* queue became empty */
                }
                free(tmp);
            }
        }
    }

    return 0; /* success */
}
