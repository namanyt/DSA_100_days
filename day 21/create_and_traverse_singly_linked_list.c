#include <stdio.h>
#include <stdlib.h>

/* Node structure for a singly linked list. */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Create a linked list from input and traverse it. */
int main() {
    int n; /* number of nodes */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    Node *head = NULL, *tail = NULL; /* list head and tail */
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x); /* read node value */

        Node *node = (Node *)malloc(sizeof(Node));
        node->data = x;
        node->next = NULL;

        if (!head) {
            head = tail = node; /* first node */
        } else {
            tail->next = node; /* append to tail */
            tail = node;
        }
    }

    Node *cur = head; /* traversal pointer */
    int first = 1;    /* spacing flag */
    while (cur) {
        if (!first) {
            printf(" ");
        }
        printf("%d", cur->data); /* print node data */
        first = 0;
        cur = cur->next;
    }
    return 0; /* success */
}
