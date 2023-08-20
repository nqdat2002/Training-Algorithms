#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;
const ll mod = 1e9 + 7;
const int oo = 1e6 + 7;

#define f first
#define s second
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define ms(s, n) memset(s, n, sizeof(s))
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a.begin(), a.end())
#define For(i, l, r) for (int i = l; i <= r; i++)
#define Fod(i, r, l) for (int i = r; i >= l; i--)
#define fillchar(a, x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void FileIO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
const int nmax = 100005;

vector<pair<int, int>> adj[nmax];
bool vs[nmax];
ll c[nmax], dist[nmax];
int n, m;

struct cmp {
	bool operator()(pair<ll, int> x, pair<ll, int> y) {
		return x.first >= y.first;
	}
};

void dijkstra(int u) {
	for (int i = 1; i <= n; ++i) dist[i] = 2 * mod;
	memset(vs, false, sizeof(vs));

	dist[u] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, cmp> pq;
	pq.push({0, u});

	while (!pq.empty()) {
		int k = pq.top().second;
		pq.pop();
		if (vs[k])
			continue;
		vs[k] = true;
		for (auto x : adj[k]) {
			int s = x.second;
			ll d_k_s = x.first;
			if (dist[k] + d_k_s < dist[s]) {
				dist[s] = dist[k] + d_k_s;
				pq.push({dist[s], s});
			}
		}
	}
	for(int u = 1; u <= n; ++u){
		cout << dist[u] << " ";
	}
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	for (int u = 1; u <= n; ++u) {
		adj[0].push_back({c[u], u});
		adj[u].push_back({c[u], 0});
	}
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({w * 2, v});
		adj[v].push_back({w * 2, u});
	}
	dijkstra(0);
	return 0;
}