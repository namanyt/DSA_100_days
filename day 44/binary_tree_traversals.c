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

/* Inorder traversal with spacing control. */
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

/* Build tree and print inorder, preorder, postorder. */
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

    int first = 1;
    inorder(root, &first);
    printf("\n");
    first = 1;
    preorder(root, &first);
    printf("\n");
    first = 1;
    postorder(root, &first);

    return 0; /* success */
}
