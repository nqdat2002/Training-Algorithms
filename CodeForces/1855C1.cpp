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
    // sieve();

    int t; cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<pair<int, int> >res;
        vector<int> a(n + 1);
        int maxx = -oo, minn = oo;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            minn = min(minn, a[i]);
            maxx = max(maxx, a[i]);
        }
        res.clear();
        if (abs(maxx) >= abs(minn) && maxx > 0) {
            int ii = -1;
            for (int i = 1; i <= n; ++i) {
                if (a[i] == maxx) {
                    ii = i;
                    break;
                }
            }
            for (int i = 1; i <= n; ++i) {
                if (a[i] < 0) {
                    a[i] += maxx;
                    res.push_back({i, ii});
                }
            }
            for (int i = 2; i <= n; ++i) {
                if (a[i] < a[i - 1]) {
                    a[i] += a[i - 1];
                    res.push_back({i, i - 1});
                }
            }
        } else {
            int ii = -1;
            for (int i = 1; i <= n; ++i) {
                if (a[i] == minn) {
                    ii = i;
                    break;
                }
            }
            for (int i = 1; i <= n; ++i) {
                if (a[i] > 0) {
                    a[i] += minn;
                    res.push_back({i, ii});

                }
            }
            for (int i = n - 1; i >= 1; --i) {
                if (a[i] > a[i + 1]) {
                    a[i] += a[i + 1];
                    res.push_back({i, i + 1});
                }
            }
        }
        cout << res.size() << endl;
        for (auto x : res) cout << x.first << " " << x.second << endl;
    }
    return 0;
}