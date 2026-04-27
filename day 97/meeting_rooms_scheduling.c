#include <stdio.h>
#include <stdlib.h>

/* Compare integers for qsort. */
static int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

/* Compute minimum number of meeting rooms required. */
int main() {
    int n; /* number of meetings */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int start[2000];
    int end[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &start[i], &end[i]);
    }

    qsort(start, n, sizeof(int), cmp_int);
    qsort(end, n, sizeof(int), cmp_int);

    int i = 0, j = 0;
    int rooms = 0, max_rooms = 0;
    while (i < n) {
        if (start[i] < end[j]) {
            rooms++;
            if (rooms > max_rooms) {
                max_rooms = rooms;
            }
            i++;
        } else {
            rooms--;
            j++;
        }
    }

    printf("%d", max_rooms);
    return 0; /* success */
}
