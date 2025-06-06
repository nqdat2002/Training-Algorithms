#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;
// ll fact(ll n, ll mod) {
//     ll res = 1;
//     for (ll i = 2; i <= n; i++) {
//         res = (res * i) % mod;
//     }
//     return res;
// }
// ll inv(ll x, ll mod) {
//     ll res = 1, p = mod - 2;
//     while (p) {
//         if (p % 2) res = (res * x) % mod;
//         x = (x * x) % mod;
//         p /= 2;
//     }
//     return res;
// }
// ll comb(ll n, ll k, ll mod) {
//     if (k > n) return 0;
//     ll x = fact(n, mod), y = (fact(k, mod) * fact(n - k, mod)) % mod;
//     return (x * inv(y, mod)) % mod;
// }

const int MAXN = 200000;
vector<ll> fact(MAXN + 1), invFact(MAXN + 1);
ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void initFact(int maxN, int mod) {
    fact[0] = 1;
    for (int i = 1; i <= maxN; i++) 
        fact[i] = (fact[i - 1] * i) % mod;
    invFact[maxN] = power(fact[maxN], mod - 2, mod);
    for (int i = maxN - 1; i >= 0; i--) 
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
}
ll comb(int n, int k, int mod) {
    if (k > n || k < 0) return 0;
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    initFact(MAXN, MOD);
    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (k == 0) {
            cout << comb(n + m - 2, n - 1, MOD) << endl;
            continue;
        }
        vector<pair<int, int>> a(k);
        for (int i = 0; i < k; i++) cin >> a[i].first >> a[i].second;

        a.push_back({n, m});
        sort(a.begin(), a.end());
        vector<ll> dp(k + 1, 0);
        dp[0] = comb(a[0].first - 1 + a[0].second - 1, a[0].first - 1, MOD);

        for (int i = 1; i <= k; i++) {
            dp[i] = comb(a[i].first - 1 + a[i].second - 1, a[i].first - 1, MOD);
            for (int j = 0; j < i; j++) {
                if (a[j].first <= a[i].first && a[j].second <= a[i].second) {
                    // calc blocked ways
                    ll cnt = dp[j] * comb(a[i].first - a[j].first + a[i].second - a[j].second,
                                           a[i].first - a[j].first, MOD) % MOD;
                    dp[i] = (dp[i] - cnt + MOD) % MOD;
                }
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}
