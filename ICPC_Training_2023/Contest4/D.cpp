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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

const int nmax = 100001;
const int maxLog = 20;

int n, q;
vector<int> adj[nmax];
ll depth[nmax], parent[nmax][maxLog];

void dfs(int u, int v, int cnt) {
	depth[u] = cnt;
	parent[u][0] = v;

	for (int i = 1; i < maxLog; ++i) {
		if (parent[u][i - 1] != -1) {
			parent[u][i] = parent[parent[u][i - 1]][i - 1];
		}
		else parent[u][i - 1] = -1;
	}

	for (int child : adj[u]) {
		if (child != v) dfs(child, u, cnt + 1);
	}
}

ll lca(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	for (int i = maxLog - 1; i >= 0; --i) {
		if (depth[u] - (1 << i) >= depth[v]) {
			u = parent[u][i];
		}
	}

	if (u == v) {
		return u;
	}
	for (int i = maxLog - 1; i >= 0; --i) {
		if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}

ll distance(int u, int v) {
	ll l = lca(u, v);
	return depth[u] + depth[v] - 2 * depth[l];
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	while (t--) {
		for (int i = 0; i < nmax; ++i) adj[i].clear();
		cin >> n;
		for (int i = 1; i < n; ++i) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(1, -1, 0);
		cin >> q;
		while (q--) {
			int u, v; cin >> u >> v;
			cout << distance(u, v) << endl;
		}
	}
	return 0;
}