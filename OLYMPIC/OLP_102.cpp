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

const int inf = 1e6;
const ll nmax = 2e5 + 5;

int n, m;
int f[nmax], h[nmax];
vector<pair<int, int> > adj[nmax];
int par[nmax][20];

struct note{
	int maxC, minC;
	note()
	{
		maxC = -inf, minC = inf;
	}
} up[nmax][20];

int find(int node){
	return (f[node] == node ? node : f[node] = find(f[node]));
}

void dfs(int u){
	for (auto pp : adj[u]){
		int v = pp.first, c = pp.second;
		if (h[v] == -1){
			par[v][0] = u;
			h[v] = h[u] + 1;
			dfs(v);
			up[v][0].maxC = c;
			up[v][0].minC = c;
		}
	}
}

void Prepare(){
	h[1] = 0;
	dfs(1);

	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			if (par[i][j - 1] != -1){
				par[i][j] = par[par[i][j - 1]][j - 1];
				up[i][j].maxC = max(up[i][j - 1].maxC, up[par[i][j - 1]][j - 1].maxC);
				up[i][j].minC = min(up[i][j - 1].minC, up[par[i][j - 1]][j - 1].minC);
			}
}

note LCA(int u, int v){
	note res = note();
	if (h[u] > h[v])
		swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (h[v] - (1 << i) >= h[u])
		{
			res.maxC = max(res.maxC, up[v][i].maxC);
			res.minC = min(res.minC, up[v][i].minC);
			v = par[v][i];
		}

	if (u == v)
		return res;

	for (int i = 19; i >= 0; i--)
		if (par[u][i] != par[v][i])
		{
			res.maxC = max(max(res.maxC, up[u][i].maxC), up[v][i].maxC);
			res.minC = min(min(res.minC, up[u][i].minC), up[v][i].minC);
			u = par[u][i], v = par[v][i];
		}
	if (u != v)
	{
		res.maxC = max(res.maxC, max(up[u][0].maxC, up[v][0].maxC));
		res.minC = min(res.minC, min(up[u][0].minC, up[v][0].minC));
	}
	return res;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	cin >> n;
	For(i, 1, n){
		adj[i].clear();
		f[i] = i;
		h[i] = -1;
		For(j, 1, 19) {
			up[i][j] = note();
			par[i][j] = -1;
		}
	}    
	For(i, 1, n - 1) {
		ll x, y, w;
		cin >> x >> y >> w;
		adj[x].pb({y, w});
		adj[y].pb({x, w});
	}
	Prepare();
	cin >> m;
	For(i, 1, m) {
		ll x, y;
		cin >> x >> y;
		note ans = LCA(x, y);
		cout << ans.minC << " " << ans.maxC << endl;
	}
	return 0;
}