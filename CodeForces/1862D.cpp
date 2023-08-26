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
		ll n; cin >> n;
		ll l = 0, r = min<ll>(2e9, 2 * n);
		while (r - l > 1) {
			ll m = (l + r) >> 1;
			if (m * (m - 1) / 2 + m < n) {
				l = m;
			} else {
				r = m;
			}
		}
		ll y = n - r * (r - 1) / 2;
		if ((r + 1) * r / 2 <= n) 
			cout << min(r + y, r + 1 + n - (r + 1) * r / 2) << "\n";
		 else 
			cout << r + y << "\n";
		
	}
	return 0;
}