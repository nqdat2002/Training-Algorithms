#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll combination(int n, int k) {
	if (k > n) return 0;
	if (k == 0 || k == n) return 1;
	ll res = 1;
	for (int i = 1; i <= k; i++) {
		res = res * (n - i + 1) / i;
		if (res > 1e15) return 1e15 + 1;
	}
	return res;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		vector<pair<int, int> > p;
		ll m; cin >> m;
		for (int n = 2; n <= 63; n++) {
			for (int k = 0; k <= n; k++) {
				ll comb = combination(n, k);
				if (comb == m) {
					p.push_back({n, k});
				}
			}
		}
		cout << p.size() << endl;
		for (auto x : p) {
			cout << "(" << x.first << "," << x.second << ") ";
		}
		cout << endl;
	}
	return 0;
}
