#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull mul_mod(ull a, ull b, ull m) {
    return (ull)((__int128)a * b % m);
}
ull power_mod(ull base, ull exp, ull mod) {
    ull res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = mul_mod(res, base, mod);
        base = mul_mod(base, base, mod);
        exp /= 2;
    }
    return res;
}
bool miller_rabin(ull n, int k = 5) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    ull d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    static const ull bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (ull a : bases) {
        if (n <= a) break;
        ull x = power_mod(a, d, n);
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
ull pollard_rho(ull n) {
    if (n % 2 == 0) return 2;
    if (miller_rabin(n)) return n;

    static mt19937_64 rng(1337);
    ull x = 2, y = 2, d = 1, c = rng() % (n - 1) + 1;

    auto f = [&](ull x, ull n, ull c) {
        return (mul_mod(x, x, n) + c) % n;
    };

    while (d == 1) {
        x = f(x, n, c);
        y = f(f(y, n, c), n, c);
        d = __gcd(x > y ? x - y : y - x, n);
        if (d == n)
            return pollard_rho(n);
    }
    return d;
}

void factorize(ull n, map<ull, int>& factors) {
    if (n == 1) return;
    if (miller_rabin(n)) {
        factors[n]++;
        return;
    }
    ull divisor = pollard_rho(n);
    factorize(divisor, factors);
    factorize(n / divisor, factors);
}
ull power(ull base, ull exp) {
    ull res = 1;
    for (ull i = 0; i < exp; ++i) res *= base;
    return res;
}

void solve() {
    long long X_input;
    if (!(cin >> X_input)) return;
    ull X = X_input;
    if (X == 1) {
        cout << 1 << "\n";
        return;
    }
    map<ull, int> factor_map;
    factorize(X, factor_map);
    vector<pair<ull, int>> factors(factor_map.begin(), factor_map.end());

    int g = factors[0].second;
    for (auto const& f : factors) {
        g = __gcd(g, f.second);
    }

    vector<int> divisors;
    for (int i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            divisors.push_back(i);
            if (i * i != g) divisors.push_back(g / i);
        }
    }
    sort(divisors.rbegin(), divisors.rend());

    for (int F : divisors) {
        long long current_F = 1;
        bool valid = true;

        for (auto const& f : factors) {
            long long item = (f.second / F) + 1;
            if (current_F > F / item) {
                valid = false;
                break;
            }
            current_F *= item;
        }

        if (valid && current_F == F) {
            ull n = 1;
            for (auto const& f : factors) {
                n *= power(f.first, f.second / F);
            }
            cout << n << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
