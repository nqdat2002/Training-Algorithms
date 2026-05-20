#include <stdio.h>
#include <stdlib.h>
#define INF 1e9
int dist[301][301];
int head[301], to[601], next[601], edge_cnt;

void add_edge(int u, int v) {
    to[edge_cnt] = v;
    next[edge_cnt] = head[u];
    head[u] = edge_cnt++;
}
void bfs(int start, int n) {
	int i;
    for (i = 1; i <= n; i++) dist[start][i] = -1;
    int queue[301], f = 0, r = 0;
    queue[r++] = start;
    dist[start][start] = 0;
    while (f < r) {
        int u = queue[f++];
        for (i = head[u]; i != -1; i = next[i]) {
            int v = to[i];
            if (dist[start][v] == -1) {
                dist[start][v] = dist[start][u] + 1;
                queue[r++] = v;
            }
        }
    }
}
void solve() {
    int n, i, j, u, v;
    if (scanf("%d", &n) != 1) return;
	edge_cnt = 0;
    for (i = 1; i <= n; i++) head[i] = -1;
    for (i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    if (n <= 2) {
        printf("%d\n", n == 2 ? 1 : 0);
        return;
    }
    for (i = 1; i <= n; i++) bfs(i, n);
    long long min_total_sum = -1;
    for (u = 1; u <= n; u++) {
        for (v = u + 1; v <= n; v++) {
            long long current_sum = 0;
            for (i = 1; i <= n; i++) {
                int *di = dist[i]; 
                int *du = dist[u];
                int *dv = dist[v];
                for (j = i + 1; j <= n; j++) {
                    int d_orig = di[j];
                    int d_new1 = di[u] + 1 + dv[j];
                    int d_new2 = di[v] + 1 + du[j];
                    int d_best = d_orig;
                    if (d_new1 < d_best) d_best = d_new1;
                    if (d_new2 < d_best) d_best = d_new2;
                    current_sum += d_best;
                }
            }
            if (min_total_sum == -1 || current_sum < min_total_sum) {
                min_total_sum = current_sum;
            }
        }
    }
    printf("%lld\n", min_total_sum);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}

