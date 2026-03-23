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

/* Search for a key in BST. */
static int search(Node *root, int key) {
    while (root) {
        if (root->val == key) {
            return 1; /* found */
        }
        if (key < root->val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return 0; /* not found */
}

/* Build BST and search for a key. */
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

    int key;
    scanf("%d", &key);
    printf(search(root, key) ? "Found" : "Not Found");
    return 0; /* success */
}
