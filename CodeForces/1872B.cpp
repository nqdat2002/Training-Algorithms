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
		int n; cin >> n;
		vector<pair<int, int>> v;
		for (int i = 0; i < n; ++i) {
			int d, s; cin >> d >> s;
			v.push_back({d, s});
		}
		int res = INT_MAX;
		for (int i = 0; i < n; ++i) {
			if (v[i].second > 2 && v[i].second % 2 == 1){
				res = min(res, v[i].first + (v[i].second >> 1));
				continue;
			}
			if (v[i].second > 2 && v[i].second % 2 == 0){
				res = min(res, v[i].first + ((v[i].second >> 1) - 1));
				continue;
			}
			res = min(res, v[i].first);
		}
		cout << res << endl;
	}
	return 0;
}