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

const int maxn = 50001;
int n, dp[maxn];
int a[maxn], ans;
vector <int> adj[maxn];

void dfs(int u, int par) {
	for (auto v : adj[u]){
		if (v == par)continue;
		dfs(v, u);
		dp[u] += dp[v];
	}
	ans = max(ans, dp[u]);
	return;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int t = 1;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			dp[i] = a[i];
		}
		for (int i = 1; i < n; i++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		ans = -oo;
		dfs(1, 0);
		cout << ans << endl;
	}
	return 0;
}