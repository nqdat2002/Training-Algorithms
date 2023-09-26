/*
	author: datnq02
*/

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

const int nmax = 1015;
const int maxlog = 16;

vector<pair<int, int> > e[nmax];
vector<pair<int, ll> > adj[maxlog];
int s[maxlog], k, m, n;
ll a[maxlog][nmax], dp[1 << maxlog][maxlog], res = -1;
int cntbfs = 0, cntdfs = 0;

void bfs(int u) {
	// using Dijsktra to find d[u][v]
	// cout << "bfs(u) = " << u << " ";
	queue<int> q;
	a[u][s[u]] = 0;
	q.push(s[u]);

	while (q.size()) {
		int y = q.front(); q.pop();
		++cntbfs;
		for (auto pp : e[y]) {
			int v = pp.first, w = pp.second;
			if (a[u][v] == -1 || a[u][v] > a[u][y] + w) {
				a[u][v] = a[u][y] + w;
				q.push(v);
			}
		}
	}
}

void dfs(int u, int mask, ll cost, int d) {
	// printf("u = %d cost = %lld d = %d dpmask = %lld\n", u, cost, d, dp[mask]);

	++cntdfs;
	ll val = dp[mask][u];
	if (val > cost || !val) {
		dp[mask][u] = cost;
		for (auto pp : adj[u]) {
			int v = pp.first;
			ll w = pp.second;
			if (res == -1 || res > cost + w) {
				if (v == 0 && d == k) res = cost + w;
				if (d < k) {
					if (!(mask & (1 << v)))
						dfs(v, (mask | (1 << v)), cost + w, d + 1);
				}
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();

	cin >> n >> m >> k;
	for (int u = 1; u <= k; ++u) cin >> s[u];
	for (int i = 1; i <= m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		e[u].push_back({v, w});
	}
	memset(a, -1, sizeof(a));
	s[0] = 1;
	bfs(0);
	for (int u = 1; u <= k; ++u) bfs(u);
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= k; ++j){
			if (i != j && a[i][s[j]] != -1) adj[i].push_back({j, a[i][s[j]]});
		}
		sort(adj[i].begin(), adj[i].end(),
			[](const pair<int, ll> &x, const pair<int, ll> &y) {
				return x.second < y.second;
		});
	}
	dfs(0, 1, 0, 0);
	// cout << cntbfs << " " << cntdfs << endl;
	cout << res << endl;
	return 0;
}