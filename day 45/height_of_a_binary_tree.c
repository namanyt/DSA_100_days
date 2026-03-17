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

/* Compute height of the tree. */
static int height(Node *root) {
    if (!root) {
        return 0; /* empty subtree */
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

/* Build tree from level order and output height. */
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
        printf("0"); /* empty tree height */
        return 0;
    }

    /* Build tree from level order. */
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

    printf("%d", height(root));
    return 0; /* success */
}
