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

/* Build tree from preorder and inorder traversals. */
static Node *build(int preorder[], int inorder[], int inStart, int inEnd, int *preIdx) {
    if (inStart > inEnd) {
        return NULL;
    }

    int rootVal = preorder[(*preIdx)++];
    Node *root = create_node(rootVal);

    int inIdx = find_index(inorder, inStart, inEnd, rootVal);
    root->left = build(preorder, inorder, inStart, inIdx - 1, preIdx);
    root->right = build(preorder, inorder, inIdx + 1, inEnd, preIdx);
    return root;
}

/* Postorder traversal with spacing control. */
static void postorder(Node *root, int *first) {
    if (!root) {
        return;
    }
    postorder(root->left, first);
    postorder(root->right, first);
    if (!*first) {
        printf(" ");
    }
    printf("%d", root->val);
    *first = 0;
}

/* Build tree and print postorder traversal. */
int main() {
    int n; /* number of nodes */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int preorder[2000];
    int inorder[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int preIdx = 0;
    Node *root = build(preorder, inorder, 0, n - 1, &preIdx);

    int first = 1;
    postorder(root, &first);
    return 0; /* success */
}
