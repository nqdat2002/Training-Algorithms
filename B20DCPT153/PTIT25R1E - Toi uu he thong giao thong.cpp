#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 305;
vector<ll> adj[MAXN];
ll dista[MAXN][MAXN];
ll n;
void bfs(int start) {
    queue<int> q;
    vector<int> d(n + 1, -1);
    d[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        dista[start][i] = d[i];
    }
}
int farthest(int start) {
    bfs(start);
    int node = start;
    for (int i = 1; i <= n; i++) {
        if (dista[start][i] > dista[start][node]) {
            node = i;
        }
    }
    return node;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            bfs(i);
        }
        int u = farthest(1);
        int v = farthest(u);
        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int d1 = dista[i][j];
                int d2 = dista[i][u] + 1 + dista[v][j];
                int d3 = dista[i][v] + 1 + dista[u][j];
                ans += min({d1, d2, d3});
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
