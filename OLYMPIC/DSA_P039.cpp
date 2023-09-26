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

const int d[] = {0, 1, 2, 4, 5, 8, 9, 10};

void solve() {
	int n, res = -1e9;
	cin >> n;
	int a[n][n + 1], f[n + 1][11] = {};
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int j = 1; j <= n; j++) {
		for (int k = 0; k < 8; k++) {
			for (int i = 0; i < n; i++)
				if (d[k] & (1 << i)) f[j][d[k]] += a[i][j];
			int x = -1e9;
			for (int i = 0; i < 8; i++)
				if ((d[k] | d[i]) == (d[k] ^ d[i]))
					x = max(x, f[j - 1][d[i]]);
			f[j][d[k]] += x;
			res = max(res, f[n][d[k]]);
		}
	}
	cout << res << endl;
}

void bitmask() {
	int n; cin >> n;
	int a[n + 1][n + 1];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) cin >> a[i][j];
	}
	int last = (1 << n) - 1;
	int f[last + 1];
	memset(f, 0, sizeof(f));
	for (int mask = 0; mask <= last; ++mask) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			if ((mask >> (i - 1)) & 1) cnt++;

		for (int i = 1; i <= n; ++i) {
			if ((mask >> (i - 1)) & 1) {
				int pp = mask ^ (1 << (i - 1));
				f[mask] = max(f[mask], f[pp] + a[cnt][i]);
			}
		}
	}
	cout << f[last] << endl;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();

	int t; cin >> t;
	while (t--) {
		bitmask();
	}
	return 0;
}
