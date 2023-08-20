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

int dp(int x, int y, int d) {
	return (y - x) / d + 1 - ((y - x) % d) == 0;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n, m, d; cin >> n >> m >> d;
		vector<int> v(m);
		for(auto &x: v) cin >> x;
		int st = 0;
		if (v[0] != 1) {
			st = 1;
			v.insert(v.begin(), 1);
		}
		v.push_back(n + 1);
		n = v.size();
		int ans = 0;
		for (int i = 1; i < n; i++) ans += dp(v[i - 1], v[i], d);
		int anstmp = ans, res = ans;
		for (int i = 1; i < n - 1; i++) {
			int cur = dp(v[i - 1], v[i + 1], d) - dp(v[i - 1], v[i], d) - dp(v[i], v[i + 1], d);
			res = anstmp + cur;
			ans = min(ans, res);
		}
		int count = 0;
		for (int i = 1; i < n - 1; i++) {
			int cur = dp(v[i - 1], v[i + 1], d) - dp(v[i - 1], v[i], d) - dp(v[i], v[i + 1], d);
			res = anstmp + cur;
			if (res == ans) 
				count++;
		}
		cout << ans << " " << count << endl;
	}
	return 0;
}

