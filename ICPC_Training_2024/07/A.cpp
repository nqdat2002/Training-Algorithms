#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 5001;
const int INF = 1e9;
int countMatches(int N) {
    vector<int> matchsticks = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};  
    vector<int>dp(N + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j : matchsticks) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }

    return dp[N];
}
int dp[max_n];
int main(int argc, char const *argv[]) {
    fill(dp, dp + max_n, INF);
    for (int i = 1; i < max_n; ++i) {
        dp[i] = i;
        for (int j = 1; j <= i; ++j) {
            dp[i] = min(dp[i], dp[j] + dp[i - j] + 2);
        }
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                int k = (int)(i / j);
                dp[i] = min(dp[i], dp[j] + dp[k] + 2);
            }
        }
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        // cout << dp[n] << endl;
        cout << countMatches(n) << endl;
    }
    return 0;
}