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
const int N = 1e5 + 5;

struct data {
	int index, val;
} tree[N * 4];

int a[N];
int n, q;

void build(int id, int l, int r) {
	if (l == r) {
		tree[id].val = a[l];
		tree[id].index = l;
		return;
	}
	int m = (l + r) >> 1;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	if (tree[id * 2].val > tree[id * 2 + 1].val) tree[id] = tree[id * 2];
	else tree[id] = tree[id * 2 + 1];
}

void update(int id, int l, int r, int u, ll val) {
	if (u < l || r < u) {
		return;
	}
	if (l == r) {
		tree[id].val = val;
		tree[id].index = l;
		return;
	}
	int m = (l + r) >> 1;
	update(id * 2, l, m, u, val);
	update(id * 2 + 1, m + 1, r, u, val);
	if (tree[id * 2].val > tree[id * 2 + 1].val) tree[id] = tree[id * 2];
	else tree[id] = tree[id * 2 + 1];
}

data get(int id, int l, int r, int u, int v) {
	if (v < l || u > r) {
		return {-1, -oo};
	}
	if (u <= l && v >= r)
		return {tree[id].index, tree[id].val};
	int m = (l + r) >> 1;
	data left = get(id * 2, l, m, u, v);
	data right = get(id * 2 + 1, m + 1, r, u, v);
	if (left.val > right.val)
		return left;
	return right;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FileIO();

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	build(1, 1, n);

	while (q--) {
		char c; cin >> c;
		int u, v; cin >> u >> v;
		if (c == 'Q') {
			data dd = get(1, 1, n, u, v);
			data d1 = get(1, 1, n, u, dd.index - 1);
			data d2 = get(1, 1, n, dd.index + 1, v);
			cout << (dd.val + max(d2.val, d1.val)) << endl;
		}
		else update(1, 1, n, u, v);
	}
	cout << endl;

	return 0;
}