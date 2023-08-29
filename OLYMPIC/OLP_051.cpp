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
const int N = 100005;

int n, m, parent[N], weight[N];
void Make(int u) {
	parent[u] = u;
	weight[u] = 0;
}

int Find(int u) {
	if (u == parent[u]) return u;
	int p = Find(parent[u]);
	weight[u] += weight[parent[u]];
	parent[u] = p;
	return parent[u];
}

void Union(int u, int v, int w) {
	int fu = Find(u);
	int fv = Find(v);

	if (fu != fv) {
		parent[fv] = fu;
		weight[fv] += (weight[u] - weight[v] + w);
	}
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) Make(i);
		while (m --) {
			char type; cin >> type;
			int u, v, w;
			if (type == '!') {
				cin >> u >> v >> w;
				Union(u, v, w);
			} else {
				cin >> u >> v;
				if (Find(u) == Find(v)) {
					cout << weight[v] - weight[u] << endl;
				}
				else cout << "UNKNOWN" << endl;
			}
		}
	}
	return 0;
}