#include <bits/stdc++.h>
using namespace std;
const int maxn = 20005;
vector<int> adj[maxn];
bool vs[maxn];
int n, m;
void bfs(int z, int x) {
    queue<int> q;
    q.push(z);
    vs[z] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (v != x && !vs[v]) {
                vs[v] = true;
                q.push(v);
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int k = 1; k <= n; k++) {
        fill(vs, vs + n + 1, false);
        vs[k] = true; 
        int cnt = 0;
        for (int u = 1; u <= n; u++) {
            if (!vs[u]) {
                bfs(u, k);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}