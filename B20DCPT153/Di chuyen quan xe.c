#include <stdio.h>
#define MAX 200005
int N, M, K;
int row_min[MAX], col_min[MAX];
int H[MAX], V[MAX];
long long bit[MAX];
void update(int idx, int val) {
    for (; idx <= M; idx += idx & -idx) bit[idx] += val;
}
long long query(int idx) {
    long long res = 0;
    for (; idx > 0; idx -= idx & -idx) res += bit[idx];
    return res;
}
int head[MAX], nxt[MAX], val_idx[MAX], edge_cnt = 0;
void add_v_val(int v, int j) {
    val_idx[++edge_cnt] = j;
    nxt[edge_cnt] = head[v];
    head[v] = edge_cnt;
}
int main() {
    if (scanf("%d %d %d", &N, &M, &K) != 3) return 0;
	int i, j, u, v, k;
    for (i = 1; i <= N; i++) row_min[i] = M + 1;
    for (j = 1; j <= M; j++) col_min[j] = N + 1;

    for (i = 0; i < K; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        if (c < row_min[r]) row_min[r] = c;
        if (r < col_min[c]) col_min[c] = r;
    }
    int R_limit = row_min[1];
    int C_limit = col_min[1];
    long long s_h = 0;
    for (i = 1; i < C_limit; i++) {
        H[i] = row_min[i] - 1;
        s_h += H[i];
    }

    long long s_v = 0;
    for (j = 1; j < R_limit; j++) {
        V[j] = col_min[j] - 1;
        s_v += V[j];
        add_v_val(V[j], j);
    }
    long long intersection = 0;
    for (i = N; i >= 1; i--) {
    	int e;
        for (e = head[i]; e; e = nxt[e]) {
            update(val_idx[e], 1);
        }
        if (i < C_limit) {
            int h_prime = H[i];
            if (h_prime > R_limit - 1) h_prime = R_limit - 1;
            intersection += query(h_prime);
        }
    }
    printf("%lld\n", s_h + s_v - intersection);

    return 0;
}

