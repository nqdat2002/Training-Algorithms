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

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int N = 200 + 13;
const int INF = 1e9;

int n, k;
int a[N];
vector<int> g[N];
int dp[N][N];
int d[N];
int tmp[N];

void dfs(int v, int p = -1){
	d[v] = 1;
	dp[v][0] = a[v];
	for (auto u : g[v]) if (u != p){
		dfs(u, v);
		int nw = max(d[v], d[u] + 1);
		forn(i, nw)
			tmp[i] = -INF;
		forn(i, d[v]) for (int j = max(0, k - i); j < d[u]; ++j)
			tmp[min(i, j + 1)] = max(tmp[min(i, j + 1)], dp[v][i] + dp[u][j]);
		forn(i, d[u])
			tmp[i + 1] = max(tmp[i + 1], dp[u][i]);
		forn(i, d[v])
			dp[v][i] = max(dp[v][i], tmp[i]);
		for (int i = d[v]; i < nw; ++i)
			dp[v][i] = tmp[i];
		d[v] = nw;
		for (int i = d[v] - 1; i > 0; --i)
			dp[v][i - 1] = max(dp[v][i - 1], dp[v][i]);
	}
}

int main(){
	scanf("%d%d", &n, &k);
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0);
	printf("%d\n", dp[0][0]);
}