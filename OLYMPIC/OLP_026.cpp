#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;
const ll mod = 1e9 + 7;
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

ll n, kk;
struct matrix {
    ll x[25][25];
};

matrix operator * (matrix a, matrix b) {
    matrix ans;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            ll s = 0;
            for (ll k = 1; k <= n; k++) {
                s = (s % mod + a.x[i][k] * b.x[k][j] % mod) % mod;
            }
            ans.x[i][j] = s;
        }
    }
    return ans;
}

matrix operator + (matrix a, matrix b) {
    matrix ans;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            ans.x[i][j] = (a.x[i][j] + b.x[i][j]) % mod;
        }
    }
    return ans;
}

matrix pow(matrix a, ll k) {
    if (k == 1) return a;
    matrix ans = pow(a, k / 2);
    ans = ans * ans;
    if (k & 1)
        ans = ans * a;
    return ans;
}

matrix I(matrix a, ll k) {
    a = pow(a, k);
    for (ll i = 1; i <= n; ++i) a.x[i][i] += 1;
    return a;
}

matrix pow2(matrix a, ll k) {
    if (k == 1) return a;
    matrix a1 = I(a, k / 2);
    matrix a2 = pow2(a, k / 2);
    matrix ans = a1 * a2;
    if (k & 1) {
        matrix b = pow(a, k);
        ans = ans + b;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> kk;
    matrix a;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> a.x[i][j];
    }
    a = pow2(a, kk);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << a.x[i][j] << " ";
        cout << endl;
    }
    return 0;
}

