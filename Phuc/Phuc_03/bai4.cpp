#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vs;
int n, m;
void dfs(int u) {
    vs[u] = true;
    for (int v : adj[u]) {
        if (!vs[v]) dfs(v);
    }
}
int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    vs.resize(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vs[i]) {
            ++res;
            dfs(i);
        }
    }
    cout << res << endl;
    return 0;
}