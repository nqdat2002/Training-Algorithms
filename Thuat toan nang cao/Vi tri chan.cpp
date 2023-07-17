// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double ld;
// typedef pair<int, int> p;
// typedef vector<vector<int> > vt;
// typedef vector<pair<int, int> > vp;
// const int oo = 1e6 + 7;

// #define f first
// #define s second
// #define pb push_back
// #define ep emplace_back
// #define sz(a) (int) a.size()
// #define ms(s, n) memset(s, n, sizeof(s))
// #define present(t, x) (t.find(x) != t.end())
// #define all(a) (a.begin(), a.end())
// #define For(i, l, r) for (int i = l; i <= r; i++)
// #define Fod(i, r, l) for (int i = r; i >= l; i--)
// #define fillchar(a, x) memset(a, x, sizeof (a))
// #define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// void FileIO() {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// }

// int m, d;
// string a, b;
// const int mod = 1000 * 1000 * 1000 + 7;
// const int N = 2025;

// int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
// int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
// int z[N][N][2];

// int solve(string s) {
//     int n = s.length();
//     for (int i = 0; i < n + 1; ++i) {
//         for (int j = 0; j < m; ++j) {
//             for (int k = 0; k < 2; ++k) {
//                 z[i][j][k] = 0;
//             }
//         }
//     }
//     z[0][0][1] = 1;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             for (int k = 0; k < 2; ++k) {
//                 for (int p = 0; p <= (k ? int(s[i] - '0') : 9); p++) {
//                     if ((i & 1) && p != d) continue;
//                     if (!(i & 1) && p == d) continue;
//                     if (!i && !p) continue;
//                     int ni = i + 1;
//                     int nj = (j * 10 + p) % m;
//                     int nk = k && (p == int(s[i] - '0'));
//                     z[ni][nj][nk] = add(z[ni][nj][nk], z[i][j][k]);
//                 }
//             }
//         }
//     }
//     int ans = 0;
//     for (int k = 0; k < 2; ++k) ans = add(ans, z[n][0][k]);
//     return ans;
// }

// bool good(string s) {
//     int rm = 0, l = s.length();
//     for (int i = 0; i < l; ++i) {
//         int p = int(s[i] - '0');
//         if ((i & 1) && p != d) return false;
//         if (!(i & 1) && p == d) return false;
//         rm = (rm * 10 + p) % m;
//     }
//     return !rm;
// }

// int main() {
//     cin >> m >> d >> a >> b;
//     int ans = 0;
//     ans = add(ans, solve(b));
//     ans = sub(ans, solve(a));
//     ans = add(ans, good(a));
//     cout << ans << endl;
//     return 0;
// }



// LUOGU_RID: 100755675
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<set>
#include<unordered_map>
#include<random>
#include<iomanip>
#include<queue>
#pragma GCC optimize("Ofast")
using namespace std;
template<typename T>
inline bool cmax(T&x, const T& y) {return x < y ? x = y, 1 : 0;}
template<typename T>
inline bool cmin(T&x, const T& y) {return y < x ? x = y, 1 : 0;}
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef unsigned long long ull;
#define X first
#define Y second
const int mod = 1e9 + 7;
inline void MOD(int&x) {x -= mod, x += x >> 31 & mod;}
inline void add(int& x, int y) {MOD(x += y);}
inline int mul(int x, int y) {return 1ll * x * y % mod;}
inline ll ksm(ll a, ll p = mod - 2)
{
    ll ans = 1;
    for (; p; p >>= 1, a = a * a % mod)if (p & 1)ans = ans * a % mod;
    return ans;
}
const int MAXN = 2e5 + 10;
int F[2009][2009];
int dfs(int pos, int sum, bool jo, bool st, int m, int D, vector<int> d)
{
    if (!pos)return !sum;
    if (st && ~F[pos][sum])return F[pos][sum];
    int ans = 0;

    int lim = st ? 9 : d[pos];
    for (int i = 0; i <= lim; i++)if (jo == 1 && i != D || !jo && i == D)
        {
            MOD(ans += dfs(pos - 1, (sum * 10 + i) % m, jo ^ 1, st || i != lim, m, D, d));
        }
    if (st)F[pos][sum] = ans;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout << fixed << setprecision(2);
    int m, D;cin >> m >> D;
    vector<int> d;
    string s;
    cin >> s;
    int ans = 1, sum = 0;
    for (int i = 1; i <= s.size(); i++)
    {
        char p = s[i - 1] - '0';
        sum = (sum * 10 + p) % m;
        if ((i & 1) && p != D || ((i + 1) & 1) && p == D);
        else ans = 0;
    }
    if (sum)ans = 0;
    reverse(s.begin(), s.end());
    d.push_back(0);
    for (auto&p : s) d.push_back(p - '0');
    memset(F, -1, sizeof(F));
    ans += mod - dfs(d.size() - 1, 0, 1, 0, m, D, d);
    cin >> s;
    reverse(s.begin(), s.end());
    d.clear();
    d.push_back(0);
    for (auto&p : s) d.push_back(p - '0');
    ans += dfs(d.size() - 1, 0, 1, 0, m, D, d);
    ans %= mod;
    cout << ans;
    return 0;
}