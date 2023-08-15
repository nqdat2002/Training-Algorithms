#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;
const int oo = 1e6 + 7;

#define fi first
#define se second
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

const int M = 1005;
const int N = 105;
const int mod = 1e9 + 7;

struct Edge {
	int a, b, c;
	bool operator < (const Edge &t) const {
		return c < t.c;
	}
} edge[M];

int n, m;
int fa[N], ka[N], vis[N];
vector<vector<ll> > gk(N, vector<ll> (N, 0));
vector<vector<ll> > tmp(N, vector<ll> (N, 0));
vector<int> gra[N];
ll ans;

int findfa(int a, int b[]) {
	return a == b[a] ? a : b[a] = findfa(b[a], b);
}

ll det(vector<vector<ll> > a, int len) {
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			// cout << a[i][j] << " ";
			a[i][j] %= mod;
		}
		// cout << endl;
	}
	ll res = 1;
	for (int i = 1; i < len; ++i) {
		for (int j = i + 1; j < len; ++j) {
			while (a[j][i]) {
				ll t = a[i][i] / a[j][i];
				for (int k = i; k < len; ++k) a[i][k] = (a[i][k] - a[j][k] * t) % mod;
				for (int k = i; k < len; ++k) swap(a[i][k], a[j][k]);
				res =- res;
			}
		}
		if (a[i][i] == 0) return 0;
		res = res * a[i][i] % mod;
	}
	return (res + mod) % mod;
}
ll dis[N];
vector <pair<ll, ll> > adj[N];
const int INF = 1e9;
int prim(int s) {
	ll ret = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q;
	for (int i = 1; i <= n; i++) dis[i] = INF;
	dis[s] = 0;
	q.push({0, s});

	while (!q.empty()) {
		auto top = q.top(); q.pop();
		ll curDis = top.fi; ll u = top.se;

		if (curDis != dis[u]) continue;
		ret += dis[u];
		dis[u] = -INF;
		for (auto &e : adj[u]) {
			int v = e.fi; int c = e.se;
			if (dis[v] > c) {
				dis[v] = c;
				q.push({ dis[v], v});
			}
		}
	}
	return ret;
}
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> edge[i].a >> edge[i].b >> edge[i].c;
		adj[edge[i].a].push_back({edge[i].b, edge[i].c});
		adj[edge[i].b].push_back({edge[i].a, edge[i].c});
	}
	sort(edge, edge + m);
	for (int i = 1; i <= n; ++i) fa[i] = i, vis[i] = 0;
	int pre = -1;
	ans = 1;
	ll weighted = 0;
	for (int h = 0; h <= m; ++h) {
		if (edge[h].c != pre || h == m) {
			for (int i = 1; i <= n; ++i) {
				if (vis[i]) {
					int u = findfa(i, ka);
					gra[u].push_back(i);
					vis[i] = 0;
				}
			}
			for (int i = 1; i <= n; ++i) {
				if (gra[i].size() > 1) {
					for (int a = 1; a <= n; ++a)
						for (int b = 1; b <= n; ++b) tmp[a][b] = 0;
					int len = gra[i].size();
					for (int a = 0; a < len; ++a) {
						for (int b = a + 1; b < len; ++b) {
							int la = gra[i][a];
							int lb = gra[i][b];
							tmp[a][b] = (tmp[b][a] -= gk[la][lb]);
							tmp[a][a] += gk[la][lb];
							tmp[b][b] += gk[la][lb];
						}
					}
					ll res = (ll)(det(tmp, len));
					ans = (ans * res) % mod;
					for (int a = 0; a < len; ++a) fa[gra[i][a]] = i;
				}
			}
			for (int i = 1; i <= n; ++i) {
				ka[i] = fa[i] = findfa(i, fa);
				gra[i].clear();
			}
			if (h == m) break;
			pre = edge[h].c;
		}
		int a = edge[h].a, b = edge[h].b, c = edge[h].c;
		int pa = findfa(a, fa), pb = findfa(b, fa);
		if (pa == pb)
			continue;
		vis[pa] = vis[pb] = 1;
		weighted += c;
		ka[findfa(pa, ka)] = findfa(pb, ka);
		gk[pa][pb] ++;
		gk[pb][pa] ++;
	}

	int flag = 0;
	for (int i = 2; i <= n && !flag; ++i) {
		if (ka[i] != ka[i - 1]) flag = 1;
	}
	cout << prim(1) << " ";
	cout << (flag ? 0 : ans) << endl;
	return 0;
}