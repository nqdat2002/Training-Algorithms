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

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[n + 1];
		for(int i = 1; i <= n; ++i) cin >> a[i];

		int cnt = 0;
		multiset<int> ms1, ms2;
		ms2.insert(a[1]);
		for (int i = 2; i <= n; ++i) {
			if (!distance(ms1.begin(), ms1.lower_bound(a[i])) && distance(ms2.begin(), ms2.lower_bound(a[i]))) {
				ms1.insert(a[i]);
				cnt++;
			}
			ms2.insert(a[i]);
		}
		cout << cnt << "\n";
	}
	return 0;
}