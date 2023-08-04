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

vector<vector<int>> g;
vector<ll> cnt;

void dfs(int v, int p) {
	if (g[v].size() == 1 && g[v][0] == p) {
		cnt[v] = 1;
		return;
	}
	for (auto u : g[v]) {
		if (u != p) {
			dfs(u, v);
			cnt[v] += cnt[u];
		}
	}
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n, q;
		cin >> n;
		g.assign(n, vector<int>());

		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cnt.assign(n, 0);
		dfs(0, -1);
		cin >> q;
		for (int i = 0; i < q; i++) {
			int c, k;
			cin >> c >> k;
			c--; k--;
			ll res = cnt[c] * cnt[k];
			cout << res << '\n';
		}
	}
	return 0;
}