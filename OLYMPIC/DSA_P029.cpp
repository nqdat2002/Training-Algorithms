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

const int nmax = 16;
int n, a[nmax][nmax], dp[(1 << nmax)][nmax];

void bitmask() {
	// int last = (1 << n) - 1;
	// memset(dp, 0x1f, sizeof(dp));
	// for (int mask = 1; mask <= last; ++mask) {
	// 	for (int u = 0; u < n; ++u) {
	// 		for (int v = 0; v < n; ++v) {
	// 			// if ((mask >> (v - 1)) & 1)
	// 			// 	dp[mask][u] = dp[mask ^ (1 << (v - 1))][v] + a[v][u];
	// 			if ((mask & (1 << v)) == 0)
	// 				dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + a[u][v]);
	// 		}
	// 	}
	// }
	// int res = 1e9;
	// for (int u = 0; u < n; ++u) res = min(res, dp[last][u]);
	// cout << res << endl;

	memset(dp, 0x1f, sizeof(dp));
	for (int u = 0; u < n; ++u) dp[1 << u][u] = 0;
	for (int mask = 1; mask < (1 << n); ++mask)
		for (int u = 0; u < n; ++u)
			for (int v = 0; v < n; ++v) 
				if ((mask & (1 << v)) == 0)
					dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + a[u][v]);
	int res = 1e9;
	for (int u = 0; u < n; ++u) res = min(res, dp[last][u]);
	cout << res << endl;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				cin >> a[i][j];
		}
		bitmask();
	}
	return 0;
}