#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        vector<vector<ll>> dp(n, vector<ll>(3, INF));
        for (int d = 0; d < 3; ++d) dp[0][d] = d * b[0];

        for (int i = 1; i < n; ++i) {
            for (int d1 = 0; d1 < 3; ++d1) {
                for (int d2 = 0; d2 < 3; ++d2) {
                    if (a[i - 1] + d2 != a[i] + d1) {
                        dp[i][d1] = min(dp[i][d1], dp[i - 1][d2] + d1 * b[i]);
                    }
                }
            }
        }
        cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;
    }
    return 0;
}
