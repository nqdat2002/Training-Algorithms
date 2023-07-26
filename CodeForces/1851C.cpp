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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
const int nmax = 2e5 + 5;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		int r = n - 1;
		ll res = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == a[0]) res += 1;
			if (res == k) {
				r = i;
				break;
			}
		}

		if (res < k) {
			cout << "NO" << endl;
			continue;
		}
		else {
			if (a[0] == a[n - 1]) {
				cout << "YES" << endl;
				continue;
			}
		}

		res = 0;
		for (int i = n - 1; i > r; --i) {
			if (a[i] == a[n - 1]) res += 1;
		}

		if (res >= k) {
			cout << "YES";
		}
		else cout << "NO";
		cout << endl;
	}
	return 0;
}