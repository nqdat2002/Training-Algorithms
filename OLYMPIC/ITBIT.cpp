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

class type1 {
	// 1: {u, v} -> a[u] = v;
	// 2: {2, p} -> sumrange(a[2], a[p])
private:
	int bit[N];
	int n;
	int a[n + 1];
public:
	void update(int u, int v) {
		int id = u;
		while (id <= n) {
			bit[id] += v;
			id += (id & (-id));
		}
	}

	int getSum(int p) {
		int id = p, res = 0;
		while (id > 0) {
			res += bit[id];
			id -= (id & (-id));
		}
		return res;
	}
};


class type2 {
	// 1: {v, l, r} -> a[l, r] += v;
	// 2: {u} -> a[u]
	// 3: {l, r} -> sumrange(a[l], a[r])

private:
	int bit[N], diff[N + 1];
	int n;
	int a[n + 1];
public:
	void prepareDist() {
		diff[1] = a[1];
		for (int i = 2; i <= n; ++i) {
			diff[i] = a[i] - a[i - 1];
		}
	}

	void update(int u, int v) {
		int id = u;
		while (id <= n) {
			bit[id] += v;
			id += (id & (-id));
		}
	}

	void updateRange1(int l, int r, int v) {
		update(l, v);
		update(r + 1, -v);
	}
	int get(int u) {
		int id = u, res = 0;
		while (id > 0) {
			res += bit[id];
			id -= (id & (-id));
		}
		return res;
	}

	vector<int> bit1;
	vector<int> bit2;


	void updatePoint(vector<int>& b, int u, int v) {
		int idx = u;
		while (idx <= n) {
			b[idx] += v;
			idx += (idx & (-idx));
		}
	}

	void updateRange2(int l, int r, int v) {
		updatePoint(bit1, l, (n - l + 1) * v);
		updatePoint(bit1, r + 1, -(n - r) * v);
		updatePoint(bit2, l, v);
		updatePoint(bit2, r + 1, -v);
	}

	int getSumOnBIT(vector<int>& b, int u) {
		int idx = u, ans = 0;
		while (idx > 0) {
			ans += b[idx];
			idx -= (idx & (-idx));
		}
		return ans;
	}

	int prefixSum(int u) {
		return getSumOnBIT(bit1, u) - getSumOnBIT(bit2, u) * (n - u);
	}

	int rangeSum(int l, int r) {
		return prefixSum(r) - prefixSum(l - 1);
	}
};

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {

		cout << endl;
	}
	return 0;
}