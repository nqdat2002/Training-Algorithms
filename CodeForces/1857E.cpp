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

const int N = 200005;
pair<int, int>x[N];
long long a[N];

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long s1 = 0, s2 = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i].first;
            x[i].second = i;
            s2 += x[i].first;
        }
        sort(x + 1, x + n + 1);
        for (int i = 1; i <= n; i++)
        {
            s2 -= x[i].first;
            s1 += x[i].first;
            a[x[i].second] = n + 1ll * x[i].first * (2 * i - n) - s1 + s2;
        }
        for (int i = 1; i <= n; i++)cout << a[i] << " \n"[i == n];
    }
    return 0;
}
