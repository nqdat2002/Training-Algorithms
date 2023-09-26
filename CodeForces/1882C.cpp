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

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[n];
		for (auto &x: a) cin >> x;
		ll respos[n + 1];
		for (int i = 0; i <= n; ++i) respos[i] = 0;
		for (int i = n - 1; i > -1; --i){
			if (a[i] >= 0)
				respos[i] = respos[i + 1] + a[i];
			else respos[i] = respos[i + 1];
		}
		ll res = 0;
		for (int i = 0; i < n; ++i){
			if (!(i & 1))
				res = max(res, respos[i + 1] + a[i]);
			else res = max(res, respos[i + 1]);
		}
		cout << res << endl;
	}
	return 0;
}