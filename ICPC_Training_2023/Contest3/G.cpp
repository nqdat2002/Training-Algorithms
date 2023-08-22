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

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first)
		return a.first > b.first;
	return a.second < b.second;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, T; cin >> n >> T;
	vector<pair<int, int> > v;
	for (int i = 0; i < n; ++i) {
		int c, d; cin >> c >> d;
		v.push_back({c, d});
	}
	sort(v.begin(), v.end(), cmp);
	ll res = 0;
	bool check[T + 1];
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++){
		for (int j = min(T, v[i].second); j >= 0; j--){
			if (!check[j]){
				res += v[i].first;
				check[j] = true;
				break;
			}
		}
	}
	cout << res << endl;
	return 0;
}