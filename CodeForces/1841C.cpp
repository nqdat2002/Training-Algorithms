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
const int val[] = {1, 10, 100, 1000, 10000};
const int INF = 1e9;

string s;
int dp[2][5][2];

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> s;
        reverse(s.begin(), s.end());
        for (int j = 0; j < 5; ++j)
            dp[0][j][0] = dp[0][j][1] = -INF;
        dp[0][0][0] = 0;
        for (auto c : s) {
            int x = c - 'A';
            for (int j = 0; j < 5; ++j)
                dp[1][j][0] = dp[1][j][1] = -INF;
            for (int j = 0; j < 5; ++j) {
                for (int t = 0; t < 2; ++t) {
                    for (int y = 0; y < 5; ++y) {
                        int nj = max(j, y);
                        int nt = t + (x != y);
                        if (nt < 2) 
                            dp[1][nj][nt] = max(dp[1][nj][nt], dp[0][j][t] + (y < nj ? -val[y] : val[y]));
                    }
                }
            }
            swap(dp[0], dp[1]);
        }
        int ans = -INF;
        for (int j = 0; j < 5; ++j)
            ans = max(ans, max(dp[0][j][0], dp[0][j][1]));
        cout << ans << '\n';
    }
    return 0;
}
