#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, ll> factor(ll n) {
    map<ll, ll> mp;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 1) mp[n]++;
    return mp;
}

int main() {
    ll X;
    cin >> X;
    if (X == 1) {
        cout << 1;
        return 0;
    }

    auto mp = factor(X);
    ll g = 0;
    for (auto &it : mp) {
        g = (g == 0 ? it.second : __gcd(g, it.second));
    }

    ll ans = -1;
    for (ll i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            vector<ll> candidates = {i};
            if (i * i != g) candidates.push_back(g / i);
            for (ll f : candidates) {
                ll fn = 1;
                bool ok = true;

                for (auto &it : mp) {
                    ll a = it.second / f;
                    fn *= (a + 1);
                    if (fn > (ll)1e18) break;
                }

                if (fn != f) continue;
                ll n = 1;
                bool overflow = false;
                for (auto &it : mp) {
                    ll p = it.first;
                    ll a = it.second / f;

                    for (int j = 0; j < a; j++) {
                        if (n > (ll)1e18 / p) {
                            overflow = true;
                            break;
                        }
                        n *= p;
                    }
                    if (overflow) break;
                }

                if (!overflow) {
                    if (ans == -1 || n < ans) ans = n;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}