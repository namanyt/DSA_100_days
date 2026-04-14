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

/* Find index of a value in inorder array. */
static int find_index(int arr[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}

/* Build tree from inorder and postorder traversals. */
static Node *build(int inorder[], int postorder[], int inStart, int inEnd, int *postIdx) {
    if (inStart > inEnd) {
        return NULL;
    }

    int rootVal = postorder[(*postIdx)--];
    Node *root = create_node(rootVal);

    int inIdx = find_index(inorder, inStart, inEnd, rootVal);

    /* Build right subtree first because postorder is Left-Right-Root. */
    root->right = build(inorder, postorder, inIdx + 1, inEnd, postIdx);
    root->left = build(inorder, postorder, inStart, inIdx - 1, postIdx);
    return root;
}

/* Preorder traversal with spacing control. */
static void preorder(Node *root, int *first) {
    if (!root) {
        return;
    }
    if (!*first) {
        printf(" ");
    }
    printf("%d", root->val);
    *first = 0;
    preorder(root->left, first);
    preorder(root->right, first);
}

/* Build tree and print preorder traversal. */
int main() {
    int n; /* number of nodes */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int inorder[2000];
    int postorder[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    int postIdx = n - 1;
    Node *root = build(inorder, postorder, 0, n - 1, &postIdx);

    int first = 1;
    preorder(root, &first);
    return 0; /* success */
}
