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

/* Zigzag (spiral) level order traversal. */
int main() {
    int n; /* number of values */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int vals[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vals[i]);
    }

    Node *root = build_tree(vals, n);
    if (!root) {
        return 0; /* empty tree */
    }

    Node *level[2000];
    int lfront = 0, lrear = 0;
    level[lrear++] = root;
    int left_to_right = 1; /* direction flag */
    int first = 1;          /* spacing flag */

    while (lfront < lrear) {
        int size = lrear - lfront;
        int temp[2000];
        for (int i = 0; i < size; i++) {
            Node *node = level[lfront++];
            temp[i] = node->val; /* collect values in this level */
            if (node->left) {
                level[lrear++] = node->left;
            }
            if (node->right) {
                level[lrear++] = node->right;
            }
        }

        if (left_to_right) {
            for (int i = 0; i < size; i++) {
                if (!first) {
                    printf(" ");
                }
                printf("%d", temp[i]);
                first = 0;
            }
        } else {
            for (int i = size - 1; i >= 0; i--) {
                if (!first) {
                    printf(" ");
                }
                printf("%d", temp[i]);
                first = 0;
            }
        }
        left_to_right = !left_to_right; /* flip direction */
    }

    return 0; /* success */
}
