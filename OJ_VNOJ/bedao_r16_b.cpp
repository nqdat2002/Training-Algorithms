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

ll func(ll x, ll y, ll k) {
	if (x >= y) swap(x, y);
	ll res = 0;
	for (int i = 1; i <= k; ++i) {
		res = max(res, (ll)(x + i) * (y + k - i));
	}
	return res;
}

pair<ll, ll> get(ll a, ll b, ll k) {
	if (a >= b) swap(a, b);
	double ff = 1.000 * (k - min(k, b - a)) / 2;
	// cout << ff << endl;
	ll aa = (ll)ceil(ff), bb = (ll)floor(ff);
	return {aa + b, bb + b};
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	while (t--) {
		ll n, k; cin >> n >> k;
		ll a[n], b[n];
		for (auto &x : a) cin >> x;
		for (auto &x : b) cin >> x;
		ll res = 0, ans = LONG_LONG_MIN;
		ll sum = 0, ans2 = LONG_LONG_MIN;
		for (int i = 0; i < n; ++i) sum += a[i] * b[i];
		int jj = 0;
		for (int i = 0; i < n; ++i) {
			pair<ll, ll> g = get(a[i], b[i], k);
			if (g.first * g.second > ans) {
				ans = (ll)(g.first * g.second);
				jj = i;
			}
			if (k < 10000) {
				ans2 = max(ans2, sum + func(a[i], b[i], k) - a[i] * b[i]);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (i != jj) res += (ll) (a[i] * b[i]);
		}
		if (k < 10000) cout << ans2 << endl;
		else cout << ans + res << endl;
	}
	return 0;
}
