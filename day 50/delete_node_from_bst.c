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

/* Find minimum node in a subtree. */
static Node *min_node(Node *root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

/* Delete a node with the given key from BST. */
static Node *delete_node(Node *root, int key) {
    if (!root) {
        return NULL;
    }
    if (key < root->val) {
        root->left = delete_node(root->left, key);
    } else if (key > root->val) {
        root->right = delete_node(root->right, key);
    } else {
        /* Node with 0 or 1 child. */
        if (!root->left) {
            Node *right = root->right;
            free(root);
            return right;
        }
        if (!root->right) {
            Node *left = root->left;
            free(root);
            return left;
        }
        /* Node with 2 children: replace with inorder successor. */
        Node *succ = min_node(root->right);
        root->val = succ->val;
        root->right = delete_node(root->right, succ->val);
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

/* Build BST, delete a key, and print inorder traversal. */
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
    root = delete_node(root, key);

    int first = 1;
    inorder(root, &first);
    return 0; /* success */
}
