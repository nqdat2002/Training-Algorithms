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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<ll> nums;

	for (ll k = 2; k <= 1000000; ++k) {
		ll val = 1 + k;
		ll p = k * k;
		for (int cnt = 3; cnt <= 63; ++cnt) {
			val += p;
			if (val > 1e18) break;
			nums.insert(val);
			if (p > (ll)(1e18) / k) break;
			p *= k;
		}
	}

	int t; cin >> t;
	for (int ii = 0; ii < t; ++ii) {
		ll n;
		cin >> n;
		if (n < 3) {
			cout << "NO" << endl;
			continue;
		}
		ll d = 4 * n - 3;
		ll sq = sqrt(d);
		ll sqd = -1;
		for (ll i = max(0ll, sq - 5); i <= sq + 5; ++i) {
			if (i * i == d) {
				sqd = i;
				break;
			}
		}
		if (sqd != -1 && (sqd - 1) % 2 == 0 && (sqd - 1) / 2 > 1) {
			cout << "YES" << endl;
			continue;
		}
		if (nums.count(n)) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}