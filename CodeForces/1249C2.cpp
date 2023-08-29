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
		vector<int> v;
		int pos2 = -1;
		while (n > 0) {
			v.push_back(n % 3);
			if (v.back() == 2) 
				pos2 = int(v.size()) - 1;
			n /= 3;
		}
		v.push_back(0);
		if (pos2 != -1) {
			int pos0 = find(v.begin() + pos2, v.end(), 0) - v.begin();
			v[pos0] = 1;
			for (int i = pos0 - 1; i >= 0; --i) {
				v[i] = 0;
			}
		}
		ll ans = 0;
		ll pw = 1;
		for (int i = 0; i < int(v.size()); ++i) {
			ans += pw * v[i];
			pw *= 3;
		}
		cout << ans << endl;
	}
	return 0;
}