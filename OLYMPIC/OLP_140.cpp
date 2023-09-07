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
	int maxsum, prefix_sum, suffix_sum, sum;
} tree[N * 4];

int a[N], n, q;

data merge(data left, data right) {
	data merged;
	merged.prefix_sum = max(left.prefix_sum, left.sum + right.prefix_sum);
	merged.suffix_sum = max(right.suffix_sum, right.sum + left.suffix_sum);
	merged.sum = left.sum + right.sum;
	merged.maxsum = max({left.maxsum, right.maxsum, left.suffix_sum + right.prefix_sum});
	return merged;
}

void build(int id, int l, int r) {
	if (l == r) {
		tree[id].maxsum = a[l];
		tree[id].prefix_sum = a[l];
		tree[id].suffix_sum = a[l];
		tree[id].sum = a[l];
		return;
	}
	int m = (l + r) >> 1;
	build(id << 1, l, m);
	build(id << 1 | 1, m + 1, r);
	// tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
	// int maxprefix_sum = tree[id].prefix_sum, maxsuffix_sum = tree[id].suffix_sum;

	// data merged, left = tree[id << 1], right = tree[id << 1 | 1];
	// merged.sum = left.sum + right.sum;
	// merged.prefix_sum = max(left.prefix_sum, left.sum + right.prefix_sum);
	// merged.suffix_sum = max(right.suffix_sum, right.sum + left.suffix_sum);
	// merged.maxsum = max({
	// 					maxprefix_sum, 
	// 					maxsuffix_sum, 
	// 					left.maxsum, 
	// 					right.maxsum, 
	// 					left.suffix_sum + right.prefix_sum
	// 				});
	// tree[id] = merged;

	tree[id].sum = tree[id << 1].sum + tree[id << 1 | 1].sum;
	tree[id].prefix_sum = max(tree[id << 1].prefix_sum, 
		tree[id << 1].sum + tree[id << 1 | 1].prefix_sum);
	tree[id].suffix_sum = max(tree[id << 1 | 1].suffix_sum, 
		tree[id << 1 | 1].sum + tree[id << 1].suffix_sum);
	int maxprefix_sum = tree[id].prefix_sum, maxsuffix_sum = tree[id].suffix_sum;
	tree[id].maxsum = max({maxsuffix_sum, 
							maxprefix_sum, 
							tree[id << 1].maxsum,
							tree[id << 1 | 1].maxsum,
							tree[id << 1].suffix_sum + tree[id << 1 | 1].prefix_sum
						});
}

void update(int id, int l, int r, int u, int val) {
	if (u < l || u > r) {
		return;
	}
	if (l == r) {
		a[u] = val;
		tree[id].maxsum = val;
		tree[id].prefix_sum = val;
		tree[id].suffix_sum = val;
		tree[id].sum = val;
		return;
	}
	int m = (l + r) >> 1;
	update(id << 1, l, m, u, val);
	update(id << 1 | 1, m + 1, r, u, val);
	tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
	int maxprefix_sum = tree[id].prefix_sum, maxsuffix_sum = tree[id].suffix_sum;

	data merged, left = tree[id << 1], right = tree[id << 1 | 1];
	merged.sum = left.sum + right.sum;
	merged.prefix_sum = max(left.prefix_sum, left.sum + right.prefix_sum);
	merged.suffix_sum = max(right.suffix_sum, right.sum + left.suffix_sum);
	merged.maxsum = max({
						maxprefix_sum, 
						maxsuffix_sum, 
						left.maxsum, 
						right.maxsum, 
						left.suffix_sum + right.prefix_sum
					});
	tree[id] = merged;

	// tree[id].sum = tree[id << 1].sum + tree[id << 1 | 1].sum;
	// tree[id].prefix_sum = max(tree[id << 1].prefix_sum, 
	// 	tree[id << 1].sum + tree[id << 1 | 1].prefix_sum);
	// tree[id].suffix_sum = max(tree[id << 1 | 1].suffix_sum, 
	// 	tree[id << 1 | 1].sum + tree[id << 1].suffix_sum);
	// int maxprefix_sum = tree[id].prefix_sum, maxsuffix_sum = tree[id].suffix_sum;
	// tree[id].maxsum = max({maxsuffix_sum, 
	// 						maxprefix_sum, 
	// 						tree[id << 1].maxsum,
	// 						tree[id << 1 | 1].maxsum,
	// 						tree[id << 1].suffix_sum + tree[id << 1 | 1].prefix_sum
	// 					});
}

data get(int id, int l, int r, int u, int v) {
	data res;
	res.prefix_sum = res.suffix_sum = res.sum = res.maxsum = INT_MIN;
	if (v < l || u > r) {
		return res;
	}
	if (u <= l && v >= r)
		return tree[id];

	int m = (l + r) >> 1;
	data left = get(id << 1, l, m, u, v);
	data right = get(id << 1 | 1, m + 1, r, u, v);
	if (v <= m) return left;
	if (u > m) return right;
	data merged;
	merged.sum = left.sum + right.sum;
	merged.prefix_sum = max(left.prefix_sum, left.sum + right.prefix_sum);
	merged.suffix_sum = max(right.suffix_sum, right.sum + left.suffix_sum);
	merged.maxsum = max({
						merged.prefix_sum, 
						merged.suffix_sum, 
						left.maxsum, 
						right.maxsum, 
						left.suffix_sum + right.prefix_sum
					});
	return merged;

	// res.sum = left.sum + right.sum;
	// res.prefix_sum = max(left.prefix_sum, 
	// 	left.sum + right.prefix_sum);
	// res.suffix_sum = max(right.suffix_sum, 
	// 	right.sum + left.suffix_sum);
	// res.maxsum = max({res.prefix_sum, 
	// 						res.suffix_sum, 
	// 						left.maxsum,
	// 						right.maxsum,
	// 						left.suffix_sum + right.prefix_sum
	// 					});
	// return res;
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
		int c, u, v; cin >> c >> u >> v;
		if (c == 1) {
			cout << get(1, 1, n, u, v).maxsum << endl;
		}
		else update(1, 1, n, u, v);
	}
	cout << endl;

	return 0;
}