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

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				char c; cin >> c;
				a[i][j] = c - 48;
			}
		}
		int pref[n + 1][n + 1], inv[n + 1][n + 1], vs[n + 1][n + 1];
		memset(pref, 0, sizeof(pref));
		memset(inv, 0, sizeof(inv));
		memset(vs, 0, sizeof(vs));
		int res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (inv[i][j] != 0) {
					pref[i][j] -= inv[i][j];
					inv[i + 1][min(n, j + 1)] += inv[i][j];
				}
				if (vs[i][j] != 0) {
					pref[i][j] += vs[i][j];
					vs[i + 1][max(j - 1, 0)] += vs[i][j];
				}
				if (vs[i][j] == 0 || inv[i][j] == 0) continue;

			}
			for (int j = 1; j < n; ++j) pref[i][j] += pref[i][j - 1];
			for (int j = 0; j < n; ++j) {
				if (pref[i][j] & 1) {
					a[i][j] = (a[i][j] == 0 ? 1 : 0);
				}
			}
			for (int j = 0; j < n; ++j) {
				if (a[i][j]) {
					res += 1;
					vs[i + 1][max(j - 1, 0)] += 1;
					inv[i + 1][min(n, j + 2)] += 1;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}