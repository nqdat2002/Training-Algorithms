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
		int n, m; cin >> n >> m;
		// if (m < 4) {
		// 	cout << "NO" << endl;
		// 	continue;
		// }
		vector<string> v(n);
		for (auto &x : v) cin >> x;
		int cnt = 0, id = 0;
		string s = "vika";
		vector<string> vv;
		for (int i = 0; i < m; ++i) {
			string ss = "";
			for (int j = 0; j < n; ++j) ss += v[j][i];
			vv.push_back(ss);
		}
		while (id < m) {
			if (vv[id].find(s[cnt]) != string::npos) {
				cnt++;
			}
			if (cnt == 4) break;
			id++;
		}
		// for (int i = 0; i < m; ++i) {
		// 	for (int j = 0; j < n; ++j) {
		// 		if (v[j][i] == s[id]) {
		// 			id++;
		// 			cnt++;
		// 			break;
		// 		}
		// 	}
		// 	if (cnt == 4) break;
		// }
		if (cnt == 4) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}