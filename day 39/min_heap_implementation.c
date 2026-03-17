#include <stdio.h>
#include <string.h>

/* Sift a node up to restore heap property. */
static void heapify_up(int heap[], int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] <= heap[idx]) {
            break;
        }
        int t = heap[parent];
        heap[parent] = heap[idx];
        heap[idx] = t;
        idx = parent;
    }
}

/* Sift a node down to restore heap property. */
static void heapify_down(int heap[], int size, int idx) {
    while (1) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;
        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest == idx) {
            break;
        }
        int t = heap[idx];
        heap[idx] = heap[smallest];
        heap[smallest] = t;
        idx = smallest;
    }
}

/* Process min-heap operations. */
int main() {
    int N; /* number of operations */
    if (scanf("%d", &N) != 1) {
        return 0; /* no valid input */
    }

    int heap[10000];
    int size = 0; /* heap size */

    for (int i = 0; i < N; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            heap[size] = x; /* insert at end */
            heapify_up(heap, size);
            size++;
        } else if (strcmp(op, "extractMin") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", heap[0]); /* output min */
                heap[0] = heap[size - 1];
                size--;
                heapify_down(heap, size, 0);
            }
        } else if (strcmp(op, "peek") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", heap[0]); /* output min */
            }
        }
    }
    return 0; /* success */
}
