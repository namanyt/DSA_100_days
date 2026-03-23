#include <stdio.h>
#include <stdlib.h>

/* BST node. */
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

/* Insert a value into BST. */
static Node *insert(Node *root, int v) {
    if (!root) {
        return create_node(v);
    }
    if (v < root->val) {
        root->left = insert(root->left, v);
    } else {
        root->right = insert(root->right, v);
    }
    return root;
}

/* Build BST and find LCA of two nodes. */
int main() {
    int n; /* number of values */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int p, q; /* target values */
    scanf("%d %d", &p, &q);

    /* LCA in BST: walk down until split point. */
    Node *cur = root;
    while (cur) {
        if (p < cur->val && q < cur->val) {
            cur = cur->left; /* both in left subtree */
        } else if (p > cur->val && q > cur->val) {
            cur = cur->right; /* both in right subtree */
        } else {
            break; /* split point found */
        }
    }

    if (cur) {
        printf("%d", cur->val);
    }
    return 0; /* success */
}
