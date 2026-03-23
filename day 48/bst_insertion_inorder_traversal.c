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

/* Insert value into BST. */
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

/* Inorder traversal (sorted order). */
static void inorder(Node *root, int *first) {
    if (!root) {
        return;
    }
    inorder(root->left, first);
    if (!*first) {
        printf(" ");
    }
    printf("%d", root->val);
    *first = 0;
    inorder(root->right, first);
}

/* Build BST and print inorder traversal. */
int main() {
    int n; /* number of values */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x); /* insert each value */
    }

    int first = 1;
    inorder(root, &first);
    return 0; /* success */
}
