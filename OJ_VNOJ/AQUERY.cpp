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

const int inf  = 1e9 + 7;
const int maxN = 1e5 + 7;

struct Node {
	ll sum, val;
};

struct IT {
	private:
		vector<Node> tree;
		int n;

		void propagate(int id, int l, int r) {
			ll &x = tree[id].val;
			if (x != -1) {
				int m = (l + r) >> 1;
				tree[2 * id].val = tree[2 * id + 1].val = x;
				tree[2 * id].sum = (m - l + 1) * x;
				tree[2 * id + 1].sum = (r - m) * x;
				x = -1;
			}
		}

		void update(int id, int l, int r, int i, int j, ll x) {
			if (l > j || r < i) return;
			if (i <= l && r <= j) {
				tree[id].val = x;
				tree[id].sum = (r - l + 1) * x;
				return;
			}
			propagate(id, l, r);
			int m = (l + r) >> 1;
			update(2 * id, l, m, i, j, x); 
			update(2 * id + 1, m + 1, r, i, j, x);
			tree[id].sum = tree[2 * id].sum + tree[2 * id + 1].sum;
		}

		long long query(int id, int l, int r, int i, int j) {
			if (l > j || r < i) return 0;
			if (i <= l && r <= j) return tree[id].sum;
			propagate(id, l, r);
			int m = (l + r) >> 1;
			return query(2 * id, l, m, i, j) + query(2 * id + 1, m + 1, r, i, j);
		}

	public:
		IT(int n): n(n) {tree.assign(4 * n + 1, {0, -1});}

		void update(int i, int j, ll x) {update(1, 1, n, i, j, x);}

		long long query(int i, int j) {return query(1, 1, n, i, j);}
};

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;

	IT tree(n);

	for (int i = 0; i < q; ++i) {
		int r; ll p;
		cin >> r >> p;

		int lo = 1, hi = r - 1, l = r;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			ll aMid = tree.query(mid, mid);
			ll x = (r - mid + 1) * aMid - tree.query(mid, r);

			if (x <= p) {
				l = mid;
				hi = mid - 1;
			} else
				lo = mid + 1;
		}

		ll aL = tree.query(l, l);
		p -= (r - l + 1) * aL - tree.query(l, r);

		ll aNew = aL + p / (r - l + 1);
		int m = l + p % (r - l + 1) - 1;
		tree.update(l, m, aNew + 1);
		tree.update(m + 1, r, aNew);
	}

	for (int i = 1; i <= n; ++i)
		cout << tree.query(i, i) << endl;
	return 0;
}