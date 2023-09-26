/*
    author: datnq02
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;
const int oo = 1e6 + 7;

#define f first
#define s second
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define ms(s, n) memset(s, n, sizeof(s))
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a.begin(), a.end())
#define For(i, l, r) for (int i = l; i <= r; i++)
#define Fod(i, r, l) for (int i = r; i >= l; i--)
#define fillchar(a, x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void FileIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const ll mod = 998244353;
const int N = int(2e5 + 5) << 1;

ll C[N];

ll extended_euclidean(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll xx, yy, g = extended_euclidean(b, a % b, xx, yy);
    x = yy, y = xx - (a / b) * yy;
    return g;
}

ll inv(ll val) {
    ll x, y, g = extended_euclidean(val, mod, x, y);
    if (g == -1)
        return 0;
    x = (x % mod + mod) % mod;
    return x;
}

ll Comb(ll n, ll k) {
    return (C[n] * inv((C[n - k] * C[k]) % mod)) % mod;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;

    int nmax = n << 1, a[nmax + 1];
    C[0] = 1;
    for (int i = 1; i <= nmax; i++) {
        cin >> a[i];
        C[i] = (C[i - 1] * i) % mod;
    }
    sort(a + 1, a + nmax + 1);

    ll sumLeft = 0, sumRight = 0;
    for (int i = 1; i <= n; ++i)
        sumLeft = (sumLeft + a[i]) % mod;

    for (int i = n + 1; i <= nmax; ++i)
        sumRight = (sumRight + a[i]) % mod;

    cout << ((sumRight - sumLeft + mod) * Comb(nmax, n)) % mod << endl;
    return 0;
}
