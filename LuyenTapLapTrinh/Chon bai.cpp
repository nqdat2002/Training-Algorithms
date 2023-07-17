#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (auto &x : a) cin >> x;
		sort(a, a + n);
		ll ans = 1;
		int ok = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] > i) {
				ok = 0;
				cout << 0 << endl;
				break;
			}
			else {
				ans *= (i - a[i] + 1);
				ans %= mod;
			}
		}
		if (ok == 1) {
			cout << ans << endl;
		}
	}
	return 0;
}
