#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
const int N = 1e5 + 5;

struct Matrix {
	ll a, b, c, d;
	Matrix operator * (Matrix x)const {
		Matrix y;
		y.a = (a * x.a + b * x.c) % mod, y.b = (a * x.b + b * x.d) % mod;
		y.c = (c * x.a + d * x.c) % mod, y.d = (c * x.b + d * x.d) % mod;
		return y;
	}
	Matrix operator + (Matrix x)const {return {(a + x.a) % mod, (b + x.b) % mod, (c + x.c) % mod, (d + x.d) % mod};}
};


Matrix ksm(Matrix x, ll y) {
	Matrix ans = {1, 0, 0, 1};
	while (y) {
		if (y & 1)ans = ans * x;
		x = x * x, y >>= 1;
	} return ans;
}

ll a[N];
struct segment {
	Matrix sum[N << 2], add[N << 2];
	void pushup(int p) {sum[p] = sum[p << 1] + sum[p << 1 | 1];}
	void update(int p, Matrix k) {
		sum[p] = sum[p] * k;
		add[p] = add[p] * k;
	}
	void pushdown(int p) {
		update(p << 1, add[p]), update(p << 1 | 1, add[p]);
		add[p] = {1, 0, 0, 1};
	}
	void build(int p, int l, int r) {
		add[p] = {1, 0, 0, 1};
		if (l == r)return sum[p] = (Matrix) {1, 1, 0, 0} * ksm({0, 1, 1, 1}, a[l] - 1), void();
		int mid = (l + r) >> 1;
		build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
		pushup(p);
	}
	void modify(int p, int l, int r, int L, int R, Matrix k) {
		if (L <= l && r <= R) return update(p, k), void();
		int mid = (l + r) >> 1;
		pushdown(p);
		if (L <= mid) modify(p << 1, l, mid, L, R, k);
		if (R > mid) modify(p << 1 | 1, mid + 1, r, L, R, k);
		pushup(p);
	}
	Matrix query(int p, int l, int r, int L, int R) {
		if (r < L || l > R) return {0, 0, 0, 0};
		if (L <= l && r <= R) return sum[p];
		int mid = (l + r) >> 1;
		pushdown(p);
		return query(p << 1, l, mid, L, R) + query(p << 1 | 1, mid + 1, r, L, R);
	}
} tree;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	tree.build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int op, l, r; cin >> op >> l >> r;
		if (op == 1) {
			int x; cin >> x;
			tree.modify(1, 1, n, l, r, ksm({0, 1, 1, 1}, x));
		}
		else cout << tree.query(1, 1, n, l, r).a << endl;
	}
}