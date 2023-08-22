#include<bits/stdc++.h>
using namespace std;
function<void(void)> ____ = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);};
#define S 3
#define C 2730
using ll = int_fast64_t;
ll N, x;
inline ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
inline ll mul(ll a, ll b, ll n) {return (a * b - (ll)(a / (long double)n * b + 1e-3) * n + n) % n;}
inline ll pow(ll a, ll b, ll n) {
    ll d = 1;
    a %= n;
    while (b) {
        if (b & 1)d = mul(d, a, n);
        a = mul(a, a, n);
        b >>= 1;
    }
    return d;
}
inline bool check(ll a, ll n) {
    ll m = n - 1, x, y; int i, j = 0;
    while (!(m & 1))m >>= 1, j++;
    x = pow(a, m, n);
    for (i = 1; i <= j; x = y, i++) {
        y = pow(x, 2, n);
        if ((y == 1) && (x != 1) && (x != n - 1))return 1;
    }
    return y != 1;
}
inline bool miller_rabin(int times, ll n) {
    if (n == 1)return 0;
    if (n == 2)return 1;
    if (!(n & 1))return 0;
    while (times--)if (check(rand() % (n - 1) + 1, n))return 0;
    return 1;
}
inline ll pollard_rho(ll n, int c) {
    ll i = 1, k = 2, x = rand() % n, y = x, d;
    while (1) {
        i++, x = (mul(x, x, n) + c) % n, d = gcd(y - x, n);
        if (d > 1 && d < n)return d;
        if (y == x)return n;
        if (i == k)y = x, k <<= 1;
    }
}
ll F = -1;
inline void findfac(ll n, int c) {
    if (n == 1)return ;
    if (miller_rabin(S, n)) {
        F = max(F, n);
        return ;
    }
    ll m = n;
    while (m == n)m = pollard_rho(n, c--);
    findfac(m, c), findfac(n / m, c);
}
map<ll, int> msk;

void solve(ll x) {
    if (x <= 1e9) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i != 0) continue;
            while (x % i == 0) {
                msk[i]++;
                x /= i;
            }
        }
        if (x != 1) msk[x]++;
        return;
    }
    F = -1;
    findfac(x, C);
    if (F == x) {
        msk[F]++;
        return;
    }
    ll y = x / F;
    x = F;
    solve(x);
    solve(y);
}

int main() {
    cin >> N >> x;
    msk.clear();
    solve(2 * N);
    //findfac(N,C);
    ll ret = 1;
    map<ll, int> m1 = msk;
    for (auto p : m1) cout << p.first << " " << p.second << endl;
    cout << endl;
    return 0;
}