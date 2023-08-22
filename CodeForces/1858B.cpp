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

int dp(int d, vector<int> x){
	int res = 0;
	for (int i = 1; i < x.size(); i++){
		res += (x[i] - x[i - 1] - 1) / d;
	}
	res += int(x.size()) - 2;
	return res;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n, m, d;
		cin >> n >> m >> d;
		vector<int> v(m);
		for(auto &x: v) cin >> x;
		v.insert(v.begin(), 1 - d);
		v.push_back(n + 1);
		int ans = 2e9;
		vector<int> res;
		for (int i = 1; i <= m; i++){
			int A = v[i] - v[i - 1] - 1, B = v[i + 1] - v[i] - 1, C = v[i + 1] - v[i - 1] - 1;
			int D = C / d - (A / d + B / d);
			if (D < ans){
				ans = D;
				res.clear();
			}
			if (D == ans) res.push_back(v[i]);
			
		}
		cout << ans + dp(d, v) - 1 << ' ' << res.size() << endl;
	}
	return 0;
}