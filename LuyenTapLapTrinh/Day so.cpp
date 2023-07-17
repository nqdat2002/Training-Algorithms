#include <bits/stdc++.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int a[n];
	int m = 1e6, res = 0;
	for (auto &x : a) {
		cin >> x;
		m = min(x, m);
	}
	for (int i = m; i >= 1; --i) {
		bool ck = true;
		for (int j = 0; j < n; ++j) {
			int r = a[j] / i;
			if (a[j] / r == i) {
				while (r && a[j] / r == i)
					r --;
				res += (r + 1);
			}
			else {
				res = 0;
				ck = false;
				break;
			}
		}
		if (ck) {
			cout << res;
			return 0;
		}
	}
}