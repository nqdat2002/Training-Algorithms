#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int main() {
    ll n, m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<ll> dist(n + 1, INF);
    vector<ll> cnt(n + 1, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    dist[1] = 0;
    cnt[1] = 1;
    pq.push({0, 1});

    while (!pq.empty()) {
        pair<ll, ll> top = pq.top();
        pq.pop();
        ll d = top.first;
        ll u = top.second;
        if (d > dist[u]) continue;

        for (ll i = 0; i < (ll)adj[u].size(); ++i) {
            ll v = adj[u][i].first;
            ll w = adj[u][i].second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                pq.push(make_pair(dist[v], v));
            }
            else if (dist[v] == dist[u] + w) {
                cnt[v] = (cnt[v] + cnt[u]);
            }
        }
    }
    cout << dist[n] << " " << cnt[n] << endl;
    return 0;
}
