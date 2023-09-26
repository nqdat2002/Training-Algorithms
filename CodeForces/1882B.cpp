/*
	author: datnq02
*/

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
		int n, ki; cin >> n;
		vector<set<int> > v(n);
		map<int, int> mp;
		for (int i = 0; i < n; ++i) {
			cin >> ki;
			for (int j = 0; j < ki; ++j) {
				int s; cin >> s;
				v[i].insert(s);
				mp[s] ++;
			}
		}
		set<int> tmp;
		int res = 0;
		for (int i = 1; i <= 100; ++i) {
			tmp.clear();
			if (mp[i]) {
				for (set<int> s : v) {
					if (find(s.begin(), s.end(), i) == s.end()) {
						tmp.insert(s.begin(), s.end());
						res = max(res, (int)tmp.size());
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}