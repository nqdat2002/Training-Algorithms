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

ll dp(ll x, ll y) {
	ll l = max(x, y) - 1;
	if (l & 1) {
		if (x < y)
			return l * l + x;
		return l * l + 2 * l - y + 2;
	} else {
		if (x < y)
			return l * l + 2 * l - x + 2;
		return l * l + y;
	}
	return 1;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int t = 1;
	while (t--) {
		ll n; cin >> n;
		for (int k = 1; k <= n; k++) {
			ll cnt = 1LL + (k - 1) * (k - 2) / 2;
			cnt = cnt * (k - 1) * (k + 4);
			cout << cnt << endl;
		}
	}
	return 0;
}