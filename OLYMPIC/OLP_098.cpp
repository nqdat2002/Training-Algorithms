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

const int maxn = 1e5 + 10;
int c[maxn], f[maxn], g[maxn];
vector<int> adj[maxn];

void dfs(int u, int par_u) {
	int sum_f = 0, sum_g = 0;

	for (int v : adj[u]) {
		if (v == par_u)
			continue;

		dfs(v, u);

		sum_f += g[v];
		sum_g += max(f[v], g[v]);
	}

	f[u] = c[u] + sum_f;
	g[u] = sum_g;
}
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int t = 1;
	while (t--) {
		int N;
		cin >> N;

		for (int i = 1; i <= N; ++i)
			cin >> c[i];

		for (int i = 1; i < N; ++i){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(1, 0);

		cout << max(f[1], g[1]);
		cout << endl;
	}
	return 0;
}