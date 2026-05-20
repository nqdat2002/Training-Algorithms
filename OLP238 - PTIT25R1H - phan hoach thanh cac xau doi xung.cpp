#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF = 1e9;
int main() {
    string s; cin >> s;
    int n = s.length();
    vector<int> dp(n + 1, INF);
    dp[0] = 0; 
    unordered_map<int, int> min_dp;
    min_dp[0] = 0; 

    int mask = 0;
    for (int i = 1; i <= n; ++i) {
        int char_bit = s[i - 1] - 'a';
        mask ^= (1 << char_bit);
        for (int k = 0; k < 26; ++k) {
            int target_mask = mask ^ (1 << k);
            if (min_dp.count(target_mask)) {
                dp[i] = min(dp[i], min_dp[target_mask] + 1);
            }
        }
        if (min_dp.count(mask)) {
            min_dp[mask] = min(min_dp[mask], dp[i]);
        } else {
            min_dp[mask] = dp[i];
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
