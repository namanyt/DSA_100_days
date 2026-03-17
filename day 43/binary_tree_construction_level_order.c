#include <stdio.h>
#include <stdlib.h>

/* Binary tree node. */
typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

/* Allocate and initialize a node. */
static Node *create_node(int v) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = v;
    n->left = NULL;
    n->right = NULL;
    return n;
}

/* Build tree from level order and print inorder traversal. */
int main() {
    int n; /* number of values */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int vals[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vals[i]); /* read level-order array */
    }

    if (n == 0 || vals[0] == -1) {
        return 0; /* empty tree */
    }

    /* Build tree from level order using a queue of nodes. */
    Node *queue[2000];
    int front = 0, rear = 0;
    Node *root = create_node(vals[0]);
    queue[rear++] = root;

    int idx = 1;
    while (front < rear && idx < n) {
        Node *cur = queue[front++];

        if (idx < n && vals[idx] != -1) {
            cur->left = create_node(vals[idx]);
            queue[rear++] = cur->left;
        }
        idx++;

        if (idx < n && vals[idx] != -1) {
            cur->right = create_node(vals[idx]);
            queue[rear++] = cur->right;
        }
        idx++;
    }

    /* Inorder traversal using an explicit stack. */
    Node *stack[2000];
    int top = -1;
    Node *curr = root;
    int first = 1; /* spacing flag */

    while (curr || top != -1) {
        while (curr) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        if (!first) {
            printf(" ");
        }
        printf("%d", curr->val);
        first = 0;
        curr = curr->right;
    }

    return 0; /* success */
}
