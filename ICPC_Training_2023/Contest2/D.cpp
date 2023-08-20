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

	while (true) {
		ll n, m; cin >> n >> m;
		if (n == 0 && m == 0)break;
		if (n == 0) {
			cout << -m*m << endl;
			continue;
		}
		ll res = -1000000000000000000;
		for (int i = 1; i <= n; i++) {
			ll a = i - 1 + (n - i + 1) * (n - i + 1);
			ll sum = i + 1;
			ll mod = m % sum;
			ll div = m / sum;
			ll x = sum - mod;
			ll b = div * div * x + (div + 1) * (div + 1) * mod;
			res = max(res, a - b);
		}
		cout << res << endl;
	}
	return 0;
}