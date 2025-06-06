#include <bits/stdc++.h>
using namespace std;
vector<int> adj[105];
bool vs[105];
int n, m;
void dfs(int u, int v) {
    vs[u] = true;
    for (int v : adj[u]) {
        if (v != v && !vs[v]) {
            dfs(v, v);
        }
    }
}
int Count(int v) {
    memset(vs, false, sizeof(vs));
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (u != v && !vs[u]) {
            ++cnt;
            dfs(u, v);
        }
    }
    return cnt;
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) adj[i].clear();
        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res = 1, node = 0;
        for (int u = 1; u <= n; ++u) {
            int c = Count(u);
            if (c > res) {
                res = c;
                node = u;
            }
        }
        cout << node << endl;
    }
}
