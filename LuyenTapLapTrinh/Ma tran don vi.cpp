#include <bits/stdc++.h>
using namespace std;
const int nmax = 1005;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n, m, X;
		cin >> n >> m >> X;
		int a[n][m];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> a[i][j];
		int dp[n + 1][m + 1];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[i + 1][j + 1] = a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int lo = 1;
				int hi = min(n - i, m - j) + 1;
				bool found = false;

				while (lo <= hi) {
					int mid = (lo + hi) / 2;
					int ni = i + mid - 1;
					int nj = j + mid - 1;
					int sum = dp[ni][nj]
					          - dp[ni][j - 1]
					          - dp[i - 1][nj]
					          + dp[i - 1][j - 1];

					if (sum >= X) {
						if (sum == X) {
							found = true;
						}

						hi = mid - 1;
					}
					else {
						lo = mid + 1;
					}
				}
				if (found == true) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
