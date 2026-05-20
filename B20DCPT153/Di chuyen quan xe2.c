#include <stdio.h>
#include <stdlib.h>

#define MAXK 200005

typedef struct {
    int x, y;
} Node;

Node a[MAXK];
int n, m, k;

int cmp_col(const void *A, const void *B) {
    Node *a = (Node*)A;
    Node *b = (Node*)B;
    if (a->y != b->y) return a->y - b->y;
    return a->x - b->x;
}

int cmp_row(const void *A, const void *B) {
    Node *a = (Node*)A;
    Node *b = (Node*)B;
    if (a->x != b->x) return a->x - b->x;
    return a->y - b->y;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
	int i, j;
    for (i = 0; i < k; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }

    int R = m + 1, D = n + 1;

    for (i = 0; i < k; i++) {
        if (a[i].x == 1 && a[i].y < R)
            R = a[i].y;
    }

    for (i = 0; i < k; i++) {
        if (a[i].y == 1 && a[i].x < D)
            D = a[i].x;
    }

    long long ans = 0;

    qsort(a, k, sizeof(Node), cmp_col);

    int *blocked = (int*)calloc(n + 2, sizeof(int));
    int ptr = 0;

    for (j = 1; j < R; j++) {
        int limit = n;

        while (ptr < k && a[ptr].y == j) {
            if (a[ptr].x < limit)
                limit = a[ptr].x;
            ptr++;
        }

        limit--; 

        for (i = limit + 1; i <= n; i++) {
            if (!blocked[i]) blocked[i] = 1;
        }

        ans += limit;
    }

    qsort(a, k, sizeof(Node), cmp_row);
    int *blocked2 = (int*)calloc(m + 2, sizeof(int));
    ptr = 0;

    for (i = 1; i < D; i++) {
        int limit = m;

        while (ptr < k && a[ptr].x == i) {
            if (a[ptr].y < limit)
                limit = a[ptr].y;
            ptr++;
        }

        limit--;

        for (j = limit + 1; j <= m; j++) {
            if (!blocked2[j]) blocked2[j] = 1;
        }

        ans += limit;
    }
    ans -= 1;

    printf("%lld\n", ans);

    free(blocked);
    free(blocked2);

    return 0;
}
