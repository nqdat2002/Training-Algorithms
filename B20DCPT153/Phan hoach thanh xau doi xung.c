#include <stdio.h>
#include <string.h>

#define MAXN 305
#define INF 1000000000

int dist[MAXN][MAXN];
int head[MAXN], to[2*MAXN], next[2*MAXN], edge_cnt;
void add_edge(int u, int v) {
    to[edge_cnt] = v;
    next[edge_cnt] = head[u];
    head[u] = edge_cnt++;
}
void bfs(int start, int n) {
    int queue[MAXN], f = 0, r = 0, i, j;
    for (i = 1; i <= n; i++) dist[start][i] = -1;
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
    int n, i, j;
    scanf("%d", &n);
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
    long long ans = -1;
	int u, v;
    for (u = 1; u <= n; u++) {
        for (v = u + 1; v <= n; v++) {
            long long sum = 0;
            for (i = 1; i <= n; i++) {
                for (j = i + 1; j <= n; j++) {
                    int d = dist[i][j];
                    int alt1 = dist[i][u] + 1 + dist[v][j];
                    int alt2 = dist[i][v] + 1 + dist[u][j];
                    if (alt1 < d) d = alt1;
                    if (alt2 < d) d = alt2;
                    sum += d;
                }
            }
            if (ans == -1 || sum < ans) ans = sum;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
