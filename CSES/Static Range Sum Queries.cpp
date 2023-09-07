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

const int N = 2e5 + 5;
ll st[4 * N];
int a[N + 5];

void update(int id, int l, int r, int i, int v) {
	if (i < l || r < i) {
		return ;
	}
	if (l == r) {
		st[id] = v;
		return ;
	}
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, i, v);
	update(id * 2 + 1, mid + 1, r, i, v);
	st[id] = st[id * 2] + st[id * 2 + 1];
}
ll get(int id, int l, int r, int u, int v) {
	if (v < l || r < u) {
		return 0;
	}
	if (u <= l && r <= v) {
		return st[id];
	}
	int mid = (l + r) >> 1;
	return (get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v));
}
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		update(1, 1, n, i, a[i]);
	}
	while (q--) {
		int type, u, v, k;
		// cin >> type;
		// if (type == 1) {
		// 	cin >> u >> k;
		// 	update(1, 1, n, u, k);
		// }
		// else {
			cin >> u >> v;
			cout << get(1, 1, n, u, v) << endl;
		// }
	}
	return 0;
}