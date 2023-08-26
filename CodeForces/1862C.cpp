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

		vector<int> a(n);
		int maxx = INT_MIN;
		for (auto &x : a) cin >> x, maxx = max(x, maxx);
		if (maxx > n) {
			cout << "No" << endl;
			continue;
		}
		vector<ll> pos(n + 1, 0);
		pos[0] += n;
		for (auto x : a) pos[x] -= 1;

		for (int i = 1; i < n; i++)
			pos[i] += pos[i - 1];
		bool check = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] != pos[i]) {
				cout << "No";
				check = 1;
				break;
			}
		}
		if (!check) cout << "Yes";
		cout << endl;
	}
	return 0;
}