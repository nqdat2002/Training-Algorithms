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
vector<ll> bit1(N);
vector<ll> bit2(N);
ll n, q;
ll a[N + 1];

void update(vector<ll> &bit, ll u, ll v) {
	ll id = u;
	while (id <= n) {
		bit[id] += v;
		id += (id & (-id));
	}
}

void updateRange(ll l, ll r, ll v) {
	update(bit1, l, (n - l + 1) * v);
	update(bit1, r + 1, -(n - r) * v);
	update(bit2, l, v);
	update(bit2, r + 1, -v);
}

ll get(vector<ll> &bit, ll u) {
	ll id = u;
	ll res = 0;
	while (id > 0) {
		res += bit[id];
		id -= (id & (-id));
	}
	return res;
}

ll getPrefixSum(ll u) {
	return get(bit1, u) - get(bit2, u) * (n - u);
}

ll getRangeSum(ll l, ll r) {
	return getPrefixSum(r) - getPrefixSum(l - 1);
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		updateRange(i, i, a[i]);
	}
	while (q--) {
		int type, u, v, k;
		cin >> type;
		if (type == 1) {
			cin >> u >> v >> k;
			updateRange(u, v, k);
		}
		else {
			cin >> u >> v;
			cout << getRangeSum(u, v) << endl;
		}
	}
	return 0;
}