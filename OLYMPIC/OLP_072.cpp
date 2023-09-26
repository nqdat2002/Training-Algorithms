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
// You are given a tree consisting of n - 1 nodes.
// Your task is to process q queries of the form: what is the distance between nodes a and b

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
 
const int MAX_L = 20;
 
int n, q, par[MAX_N][MAX_L], dep[MAX_N];
vector<int> adj[MAX_N];
 
void dfs(int u, int p = 0) {
    par[u][0] = p;
    for (int i = 1; i < MAX_L; i++) 
        par[u][i] = par[par[u][i - 1]][i - 1];
    for (int v : adj[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}
 
int ancestor(int u, int k) {
    for (int i = 0; i < MAX_L; i++) 
        if (k & (1 << i)) 
            u = par[u][i];
    return u;
}
 
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    u = ancestor(u, dep[u] - dep[v]);
    if (u == v) return u;
    for (int i = MAX_L - 1; i >= 0; i--)
        if (par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
    return par[u][0];
}

int distance(int u, int v){
	int l = lca(u, v);
	return dep[u] + dep[v] - 2 * dep[l];
}
 
void solve() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int t = 1;
	while (t--) {
		solve();
		cout << endl;
	}
	return 0;
}