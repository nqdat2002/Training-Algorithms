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

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		ll c[n], p[k];
		for (auto &x : c) cin >> x;
		for (auto &x : p) cin >> x, c[--x] = 0;

		vector<ll> min_cost(n, 2 * mod);
		vector<vector<int> > in_mix(n);
		vector<map<int, ll> > min_list(n);

		for (int i = 0; i < n; ++i) {
			int m; cin >> m;
			if (m == 0) continue;
			ll sum = 0;
			for (int j = 0; j < m; ++j) {
				int e; cin >> e;
				e --;
				in_mix[e].push_back(i);
				sum += c[e];
				min_list[i][e] = c[e];
			}
			min_cost[i] = sum;
		}

		priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
		for (int i = 0; i < n; ++i) {
			pq.emplace(c[i], i);
			pq.emplace(min_cost[i], i);
		}
		while (pq.size()) {
			pair<ll, int> top = pq.top(); pq.pop();
			if (top.first != c[top.second]) continue;
			int e = top.second;

			for (int x : in_mix[e]) {
				ll bef = min_list[x][e];
				min_list[x][e] = c[e];
				min_cost[x] += c[e] - bef;

				if (min_cost[x] < c[x]) {
					c[x] = min_cost[x];
					pq.emplace(c[x], x);
				}
			}
		}
		for (auto x : c) cout << x << " ";
		cout << endl;
	}
	return 0;
}