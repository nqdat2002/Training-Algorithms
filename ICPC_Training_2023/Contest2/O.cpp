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

vector<ll> fact;

void init(int n, int m){
	ll sumfact = 2, x = n;
	fact.push_back(0 % m);
	fact.push_back(2 % m);
	ll ff = 1;
	for (int i = 2; i <= n; ++i){
		ff *= i;
		sumfact += (i * (ff + x));
		sumfact %= m;
		fact.push_back(sumfact);
	}
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int n, m; cin >> n >> m;
	ll a[n];
	ll mx = LONG_LONG_MIN;
	for (auto &x: a) cin >> x, x %= m, mx = max(mx, x);
	init(mx, m);
	
	// for (auto x: fact) cout << x << endl;
	cout << fact[mx] << endl;
	return 0;
}