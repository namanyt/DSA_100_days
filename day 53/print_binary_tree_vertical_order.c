#include <stdio.h>
#include <stdlib.h>

/* Binary tree node. */
typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

/* Pair of node and horizontal distance. */
typedef struct Pair {
    Node *node;
    int hd;
} Pair;

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

/* Print vertical order traversal. */
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

    Pair queue[4000];
    int front = 0, rear = 0;
    queue[rear++] = (Pair){root, 0};

    int hd_vals[4000];
    int nodes[4000];
    int size = 0;
    int min_hd = 0, max_hd = 0;

    /* BFS to capture nodes with their horizontal distances. */
    while (front < rear) {
        Pair p = queue[front++];
        hd_vals[size] = p.hd;
        nodes[size] = p.node->val;
        size++;
        if (p.hd < min_hd) {
            min_hd = p.hd;
        }
        if (p.hd > max_hd) {
            max_hd = p.hd;
        }
        if (p.node->left) {
            queue[rear++] = (Pair){p.node->left, p.hd - 1};
        }
        if (p.node->right) {
            queue[rear++] = (Pair){p.node->right, p.hd + 1};
        }
    }

    for (int hd = min_hd; hd <= max_hd; hd++) {
        int first = 1;
        for (int i = 0; i < size; i++) {
            if (hd_vals[i] == hd) {
                if (!first) {
                    printf(" ");
                }
                printf("%d", nodes[i]);
                first = 0;
            }
        }
        if (hd < max_hd) {
            printf("\n");
        }
    }

    return 0; /* success */
}
