#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
vector<int> adj[maxn];
bool vs[maxn];
int n, m;
void dfs(int u) {
    vs[u] = true;
    for (int v : adj[u]) {
        if (!vs[v]) dfs(v);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    bool ok = false;
    for (int u = 1; u <= n; u++) {
        if (!vs[u]) {
            cout << u << endl;
            ok = true;
        }
    }
    if (!ok) cout << 0 << endl;
}