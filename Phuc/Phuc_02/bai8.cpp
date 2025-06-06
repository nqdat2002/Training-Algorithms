#include <bits/stdc++.h>
using namespace std;
vector<int> adj[105];
bool vs[105];
int n, m, u, v;
void dfs(int x, int y) {
    vs[x] = true;
    for (int z : adj[x])
        if (z != y && !vs[z]) dfs(z, y);
}
bool check(int x) {
    memset(vs, false, sizeof(vs));
    if (x == u || x == v) return false;
    dfs(u, x);
    return !vs[v];
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m >> u >> v;
        for (int i = 1; i <= n; ++i) adj[i].clear();
        for (int i = 0; i < m; ++i) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
        }
        int cnt = 0;
        for (int x = 1; x <= n; ++x)
            if (check(x)) ++cnt;
        cout << cnt << endl;
    }
}