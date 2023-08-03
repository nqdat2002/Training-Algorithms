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

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10); cout.setf(ios::fixed);

    int t;
    cin >> t;
    while (t--) {
        int n, d, h;
        cin >> n >> d >> h;
        vector<int> y(n);
        for (int i = 0; i < n; i++) {
            cin >> y[i];
        }
        long double ans = (long double)d * h / 2.0;
        for (int i = 0; i + 1 < n; ++i) {
            if (y[i + 1] >= y[i] + h) ans += (long double)d * h / 2.0;
            else {
                long double d2 = (long double)d * (y[i] + h - y[i + 1]) / h;
                long double nh = y[i + 1] - y[i];
                ans += (d + d2) / 2.0 * nh;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}