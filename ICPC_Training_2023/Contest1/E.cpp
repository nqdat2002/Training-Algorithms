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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
const int maxN = 205;
const int maxS = maxN * maxN;

int n, a, x[maxN], dp[2][2 * maxS];

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n >> a;
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
            x[i] -= a;
        }
        memset(dp, 0, sizeof dp);
        dp[0][maxS] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2 * maxS; ++j) {
                if (dp[0][j] > 0) {
                    add(dp[1][j], dp[0][j]);
                    add(dp[1][j + x[i]], dp[0][j]);
                }
            }
            for (int j = 0; j < 2 * maxS; ++j) {
                dp[0][j] = dp[1][j];
                dp[1][j] = 0;
            }
        }
        cout << (dp[0][maxS] - 1 + mod) % mod;
        cout << endl;
    }
    return 0;
}