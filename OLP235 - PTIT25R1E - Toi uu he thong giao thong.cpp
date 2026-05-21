#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 305;
vector<ll> adj[MAXN];
ll dista[MAXN][MAXN];
ll n;
void bfs(ll start) {
    queue<ll> q;
    vector<ll> d(n + 1, -1);
    d[start] = 0;
    q.push(start);
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for (ll v : adj[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    for (ll i = 1; i <= n; i++) {
        dista[start][i] = d[i];
    }
}
ll farthest(ll start) {
    bfs(start);
    ll node = start;
    for (ll i = 1; i <= n; i++) {
        if (dista[start][i] > dista[start][node]) {
            node = i;
        }
    }
    return node;
}
int main() {
    int T; cin >> T;
    while (T--) {
        cin >> n;
        for (ll i = 1; i <= n; i++) adj[i].clear();
        for (ll i = 0; i < n - 1; i++) {
            ll u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (ll i = 1; i <= n; i++) bfs(i);
        ll u = farthest(1), v = farthest(u);
        ll ans = 0;
        for (ll i = 1; i <= n; i++) {
            for (ll j = i + 1; j <= n; j++) {
                ll d1 = dista[i][j];
                ll d2 = dista[i][u] + 1 + dista[v][j];
                ll d3 = dista[i][v] + 1 + dista[u][j];
                ans += min({d1, d2, d3});
            }
        }
        cout << ans << "\n";
    }
    return 0;
}