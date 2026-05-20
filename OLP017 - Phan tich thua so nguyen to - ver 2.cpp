#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mul_mod(ll a, ll b, ll mod) {
    return (ll)((__int128)a * b % mod);
}
ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = mul_mod(res, base, mod);
        base = mul_mod(base, base, mod);
        exp /= 2;
    }
    return res;
}
bool miller_rabin(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    
    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    static const ll bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (ll a : bases) {
        if (n <= a) break;
        ll x = power(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int r = 1; r < s; r++) {
            x = mul_mod(x, x, n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}
ll pollard_rho(ll n) {
    if (n % 2 == 0) return 2;
    if (miller_rabin(n)) return n;
    
    ll x = 2, y = 2, d = 1, c = 1;
    auto f = [&](ll x, ll n, ll c) {
        return (mul_mod(x, x, n) + c) % n;
    };
    
    while (d == 1) {
        x = f(x, n, c);
        y = f(f(y, n, c), n, c);
        d = __gcd(abs(x - y), n);
        if (d == n) { 
            x = rand() % (n - 2) + 2;
            y = x;
            c = rand() % (n - 1) + 1;
            d = 1;
        }
    }
    return d;
}
void factorize(ll n, map<ll, int>& factors) {
    if (n == 1) return;
    if (miller_rabin(n)) {
        factors[n]++;
        return;
    }
    ll divisor = pollard_rho(n);
    factorize(divisor, factors);
    factorize(n / divisor, factors);
}

void solve() {
    ll n;
    if (cin >> n) {
        map<ll, int> factors;
        factorize(n, factors);
        for (pair<ll, int> p : factors) {
            cout << p.first << " " << p.second << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}
