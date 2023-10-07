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

const int N = 200005;
const int m = 5 * 1000 * 1000;
ll bit[N], inc[N];
int n, k;
ll a[N + 1];

void update(int u, int v) {
	int id = u;
	while (id <= n) {
		bit[id] += v;
		id += (id & (-id));
	}
}

ll get(int u) {
	int id = u;
	ll res = 0;
	while (id > 0) {
		res += bit[id];
		id -= (id & (-id));
	}
	return res;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	while (t--) {
		memset(bit, 0, sizeof(bit));
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {cin >> a[i]; inc[i] = 1;}

		for (int l = 2; l <= k; ++l) {
			for (int i = 1; i <= n; ++i) {
				update(a[i], inc[i]);
				inc[i] = get(a[i] - 1);
			}
		}
		ll res = 0;
		for (int i = 1; i <= n; ++i) res = (res + inc[i]) % m;
		cout << res << endl;
	}
	return 0;
}