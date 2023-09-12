#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
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

const int N = 1e6 + 5;
int n, q, a[N], shift;

struct SumSegtree {
    ll f[N << 1];

    void init() {
        for (int i = 0; i < n; i++)
            f[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            f[i] = f[i << 1] + f[i << 1 | 1];
    }

    void update(int u, ll v) {
        f[u += n] = v;
        for (u >>= 1; u > 0; u >>= 1)
            f[u] = f[u << 1] + f[u << 1 | 1];
    }

    ll get(int l, int r) {
        ll res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res += f[l++];
            if (r & 1)
                res += f[--r];
        }
        return res;
    }
} sst;

struct MinSegtree {
    pair<int, int> f[N << 1];

    void init() {
        for (int i = 0; i < n; i++)
            f[i + n] = {a[i], i};
        for (int i = n - 1; i > 0; i--)
            f[i] = min(f[i << 1], f[i << 1 | 1]);
    }

    void update(int i, int v) {
        f[i + n] = {v, i};
        for ((i += n) >>= 1; i > 0; i >>= 1)
            f[i] = min(f[i << 1], f[i << 1 | 1]);
    }

    pair<int, int> get(int l, int r) {
        pair<int, int> res = {oo, oo};
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = min(res, f[l++]);
            if (r & 1)
                res = min(res, f[--r]);
        }
        return res;
    }
} mst;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    FileIO();

    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    sst.init();
    mst.init();
    while (q--) {
        int type;
        cin >> type;
        switch (type) {
        case 1:{
            int d;
            cin >> d;
            shift = (shift + d) % n;
            break;
        }
        case 2:{
            int at_zero = (n - shift) % n;
            int s, e, p;
            cin >> s >> e >> p;
            s = (s - 1 - shift + n) % n;
            e = (e - 1 - shift + n) % n;
            pair<int, int> replaced;
            if (s <= e) {
                if (s <= at_zero && at_zero <= e) {
                    pair<int, int> lef = mst.get(at_zero, e + 1);
                    pair<int, int> rig = mst.get(s, at_zero);
                    if (lef.first == rig.first)
                        replaced = lef;
                    else
                        replaced = min(lef, rig);
                }
                else replaced = mst.get(s, e + 1);
                // cout << replaced.first << " " << replaced.second << endl;
            }
            else {
                if (e < at_zero && at_zero < s) {
                    pair<int, int> lef = mst.get(s, n);
                    pair<int, int> rig = mst.get(0, e + 1);
                    if (lef.first == rig.first)
                        replaced = lef;
                    else
                        replaced = min(lef, rig);
                    // cout << replaced.first << " " << replaced.second << endl;
                }
                else if (s <= at_zero && at_zero < n) {
                    pair<int, int> lef = mst.get(at_zero, n);
                    pair<int, int> rig = min(mst.get(0, e + 1), mst.get(s, at_zero));

                    if (lef.first == rig.first)
                        replaced = lef;
                    else
                        replaced = min(lef, rig);
                    // cout << replaced.first << " " << replaced.second << endl;
                }
                else if (0 <= at_zero && at_zero <= e) {
                    pair<int, int> lef = min(mst.get(at_zero, e + 1), mst.get(s, n));
                    pair<int, int> rig = mst.get(0, at_zero);
                    if (lef.first == rig.first)
                        replaced = lef;
                    else
                        replaced = min(lef, rig);
                    // cout << replaced.first << " " << replaced.second << endl;
                }
            }
            mst.update(replaced.second, p);
            sst.update(replaced.second, p);
            break;
        }
        case 3: {
            int s, e;
            cin >> s >> e;
            s = (s - 1 - shift + n) % n;
            e = (e - 1 - shift + n) % n;
            if (s <= e)
                cout << sst.get(s, e + 1) << "\n";
            else
                cout << sst.get(s, n) + sst.get(0, e + 1) << "\n";

            break;
        }
        }
    }
    return 0;
}