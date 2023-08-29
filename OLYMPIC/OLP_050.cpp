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
int n, m, parent[N], cnt[N];
void Make(int u) {
	parent[u] = u;
}

int Find(int u) {
	if (u == parent[u]) return u;
	int p = Find(parent[u]);
	parent[u] = p;
	return parent[u];
}

void Union(int u, int v) {
	int fu = Find(u);
	int fv = Find(v);

	if (fu != fv) {
		parent[fv] = fu;
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
		for (int i = 1; i <= n; ++i) {
			cnt[i] = 1;
			Make(i);
		}

		for (int i = 1; i <= m; ++i) {
			int u, v; cin >> u >> v;
			Union(u, v);
		}

		for (int u = 1; u <= n; ++u) {
			parent[u] = Find(parent[u]);
			cnt[parent[u]]++;
		}

		cout << *max_element(cnt + 1, cnt + n + 1) - 1 << endl;
	}
	return 0;
}