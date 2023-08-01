#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		ll delta = 0, ans = 0, sum = 0, mx = 0;
		for (int i = 0; i < n; ++i) {
			ll x; cin >> x;
			sum += x;
			mx = max(mx, sum);
			if (sum - mx < delta) {
				delta = sum - mx;
				ans = mx;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}