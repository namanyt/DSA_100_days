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

/* Build tree from level-order array where -1 means null. */
static Node *build_tree(int vals[], int n) {
    if (n == 0 || vals[0] == -1) {
        return NULL;
    }

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

    return root;
}

/* Find LCA in a general binary tree. */
static Node *lca(Node *root, int p, int q) {
    if (!root) {
        return NULL;
    }
    if (root->val == p || root->val == q) {
        return root;
    }
    Node *left = lca(root->left, p, q);
    Node *right = lca(root->right, p, q);
    if (left && right) {
        return root; /* split point */
    }
    return left ? left : right;
}

/* Build tree and print LCA. */
int main() {
    int n; /* number of values */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int vals[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vals[i]);
    }

    int p, q; /* target values */
    scanf("%d %d", &p, &q);

    Node *root = build_tree(vals, n);
    Node *ans = lca(root, p, q);
    if (ans) {
        printf("%d", ans->val);
    }
    return 0; /* success */
}
