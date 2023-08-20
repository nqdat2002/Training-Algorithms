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
vector<ll> factorial;
vector<ll> fsum;
map<ll, int> mp;

void calcFx(ll x, int m) {
	factorial.push_back(0);
	factorial.push_back(2);
	ll sum = 2;
	ll factor = 1;
	for (ll i = 2; i <= x; ++i) {
		factor *= i;
		sum += (i * factor % m + i % m);
		sum %= m;
		factorial.push_back(sum);
	}
	for(auto x: factorial) cout << x << endl;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	ll a[n];
	calcFx(1000, m);
	// for (auto &x : a) cin >> x;

	// ll sum = 0;
	// for (auto x : a) {
	// 	if (mp[x]) {
	// 		sum += factorial[x] % m;
	// 		sum %= m;
	// 	}
	// }
	// cout << sum << endl;
	return 0;
}